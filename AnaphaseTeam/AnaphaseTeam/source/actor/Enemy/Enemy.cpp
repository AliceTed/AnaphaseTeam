#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/shape/Sphere.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/camera/CameraController.h"

Enemy::Enemy() :
	Actor(
		Transform(GSvector3(0, 0, 0), GSvector3(0, 180, 0)),
		MODEL_ID::BOSS,
		Sphere(GSvector3(0, 7, 0), 7.0f),
		Actor_Tag::ENEMY
		),
	m_points(),
	m_core(GSvector3(0, 0, 0), 1),
	m_corecolor(1, 1, 1, 1),
	m_group(make_shared<CollisionGroup>(this)),
	m_color(1, 1, 1, 1),
	m_state(State::STAND)
{
}

Enemy::~Enemy()
{
}

void Enemy::initialize()
{
	Actor::initialize();
	m_animatorOne.changeAnimation((ANIMATION_ID)1, true);
	//m_points.clear();
	//createPoint();
	m_corecolor = GScolor(1, 1, 1, 1);
	//for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.createCollision(this, m_group); });

	m_color = GScolor(1, 1, 1, 1);
	m_state = State::STAND;
}

void Enemy::update(float deltatime)
{
	m_animatorOne.update(deltatime);
	pos = getAnimEachPos();
	//m_core.transfer(pos.at(static_cast<unsigned int>(Element::HEAD)));
	//for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.update(deltatime, pos); });

	m_value = rand();
	enemyAttack();
}

void Enemy::draw(const Renderer& _renderer, const Camera& _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	//for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.draw(_renderer); });
	//m_core.draw(_renderer, m_corecolor);
}

void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.getPosition();
	_player->look_at(_camera, &target);

	if (m_value % 50 == 0)
		dirCalc(_player);
}

void Enemy::addCollisionGroup(CollisionManager* _manager)
{
	_manager->add(m_group);
}

void Enemy::createPoint()
{
	vector<GSvector3> pos = getAnimEachPos();
	m_points.emplace_back(CollisionActorType::ENEMY_LEFT, Element::LEFT_LEG);
	m_points.emplace_back(CollisionActorType::ENEMY_RIGHT, Element::RIGHT_LEG);

	m_core.transfer(pos.at(static_cast<GSuint>(Element::HEAD)));
}

vector<GSvector3> Enemy::getAnimEachPos()
{
	const GSuint n = m_animatorOne.getNumBones();
	vector<GSvector3> res;
	for (GSuint i = 0; i < n; i++)
	{
		Transform transform(m_animatorOne.getMatrixVector()[i]);
		GSmatrix4 m = transform.parentSynthesis(m_transform);
		res.emplace_back(m.getPosition());
	}
	return res;
}

void Enemy::enemyAttack()
{
	Shape_Ptr shape = std::make_shared<Sphere>(GSvector3(0, 1, 1), 1);
	Collision_Ptr actor = std::make_shared<CollisionActor>(shape, CollisionActorType::ENEMY_ATTACK);

	if (m_value % 100 == 0)
	{
		m_state = State::ATTACK;

		m_animatorOne.changeAnimation((ANIMATION_ID)0);
		actor->set_collision_enter([&](Actor* _actor, CollisionActorType _type)
		{
			Player* _player = dynamic_cast<Player*>(_actor);
			if (_player == nullptr)return;
			m_color = GScolor(1, 0, 0, 1);
		});
		actor->set_update([&](float deltaTime, Shape_Ptr _shape) { _shape->transfer(pos.at(static_cast<GSuint>(64))); });
		actor->set_dead([&]()->bool { return m_state == State::STAND; });
		actor->set_draw([&](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer, m_color); });
		m_group->add(actor);
	}
	if (m_animatorOne.isEndCurrentAnimation())
	{
		m_state = State::STAND;
		m_animatorOne.changeAnimation(ANIMATION_ID(1), true);
	}
}

void Enemy::dirCalc(Player* _player)
{
	if (m_state == State::STAND)
	{
		GSvector3 vector = _player->getPosition() - m_transform.getPosition();
		float radian = atan2(vector.x, vector.z);
		float degree = radian * 180.0f / M_PI;
		m_transform.setYaw(degree);
	}
}