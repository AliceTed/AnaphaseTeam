#include "../../../header/actor/Boss/Boss.h"
#include "../../../header/shape/Sphere.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/camera/CameraController.h"

Boss::Boss() :
	Actor(
		Transform({ 0,0,0 }, GSquaternion(0, 0, 0, 1)),
		MODEL_ID::BOSS,
		Sphere(GSvector3(0, 7, 0), 7.0f),
		Actor_Tag::BOSS
		),
	m_core(GSvector3(0, 0, 0), 1),
	m_corecolor(1, 1, 1, 1),
	m_group(make_shared<CollisionGroup>(this)),
	m_color(1, 1, 1, 1),
	m_state(State::STAND)
{
}

Boss::~Boss()
{
}

void Boss::initialize()
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

void Boss::update(float deltatime)
{
	m_animatorOne.update(deltatime);
	pos = getAnimEachPos();
	//m_core.transfer(pos.at(static_cast<unsigned int>(Element::HEAD)));
	//for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.update(deltatime, pos); });

	m_value = rand();
	enemyAttack();
}

void Boss::draw(const Renderer& _renderer, const Camera& _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	//for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.draw(_renderer); });
	//m_core.draw(_renderer, m_corecolor);
}

void Boss::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.getPosition();
	_player->look_at(_camera, &target);

	if (m_value % 50 == 0)
		dirCalc(_player);
}

void Boss::addCollisionGroup(CollisionManager* _manager)
{
	_manager->add(m_group);
}

const GSvector3 Boss::getPosition() const
{
	return m_transform.getPosition();
}

vector<GSvector3> Boss::getAnimEachPos()
{
	const GSuint n = m_animatorOne.getNumBones();
	vector<GSvector3> res;
	for (GSuint i = 0; i < n; i++)
	{
		Transform transform(m_animatorOne.getMat()[i]);
		GSmatrix4 m = transform.parent_synthesis(m_transform).matrix();
		res.emplace_back(m.getPosition());
	}
	return res;
}

void Boss::enemyAttack()
{
	//Shape_Ptr shape = std::make_shared<Sphere>(GSvector3(0, 1, 1), 1);
//	Collision_Ptr actor = std::make_shared<CollisionActor>(shape, Collision_Tag::ENEMY_ATTACK);

	if (m_value % 100 == 0)
	{
		m_state = State::ATTACK;

		m_animatorOne.changeAnimation((ANIMATION_ID)0);
	/*	actor->set_collision_enter([&](Hit* hit)
		{
			Player* _player = dynamic_cast<Player*>(hit->m_paremt);
			if (_player == nullptr)return;
			m_color = GScolor(1, 0, 0, 1);
		});
		actor->set_update([&](float deltaTime, Shape_Ptr _shape) { _shape->transfer(pos.at(static_cast<GSuint>(64))); });
		actor->set_dead([&]()->bool { return m_state == State::STAND; });
		actor->set_draw([&](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer, m_color); });
		m_group->add(actor);*/
	}
	if (m_animatorOne.isEndCurrentAnimation())
	{
		m_state = State::STAND;
		m_animatorOne.changeAnimation(ANIMATION_ID(1), true);
	}
}

void Boss::dirCalc(Player* _player)
{
	if (m_state == State::STAND)
	{
		GSvector3 vector = _player->getPosition() - m_transform.getPosition();
		float radian = atan2(vector.x, vector.z);
		float degree = radian * 180.0f / M_PI;
		m_transform.m_rotate = GSquaternion(degree, GSvector3(0, 1, 0));
	}
}
