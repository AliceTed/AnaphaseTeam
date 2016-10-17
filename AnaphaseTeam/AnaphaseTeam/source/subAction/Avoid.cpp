#include "../../header/subAction/Avoid.h"
#include "../../header/actor/Player/Player.h"

const float Avoid::VELOCITY = 7.5f;
const float Avoid::TIME = 0.2f;
Avoid::Avoid(Player* _player)
	:m_player(_player),
	m_prebious(0,0,0),
	m_lerp(GSvector3(0, 0, 0)),
	m_justAvoidFlg(false),
	m_justTime(0.1f)
{
}

Avoid::~Avoid()
{
}

void Avoid::initialize()
{
	m_justAvoidFlg = false;
	m_justTime.initialize();
	GSvector3 dir = m_player->inputDirection();
	dir.normalize();
	m_lerp.start(dir,dir*VELOCITY, TIME);
	m_prebious = m_lerp.current();
	m_player->justAvoid(this);
}

void Avoid::update(float deltaTime)
{
	m_justTime.update(deltaTime);
	m_lerp.update(deltaTime);
	m_player->avoidAction(m_lerp.current() - m_prebious);
	m_prebious = m_lerp.current();
	//スリープでスローモーション仮実装
	if (m_justAvoidFlg)
	{
		Sleep(60);
	}
	
}

const bool Avoid::isEnd() const
{
	return m_lerp.isEnd();
}

/**
* @fn
* @brief ジャスト回避用当たり判定があるかどうか
*/
bool Avoid::isjustTimeEnd()
{
	return m_justTime.isEnd();
}
/**
* @fn
* @brief ジャスト回避の当たり判定
*/
void Avoid::justAvoidRange(Group_Ptr _group, Transform & _transform)
{
	float radius = 1.5f;
	GSvector3 pos(_transform.getPosition());
	pos.y += 1.0f;
	Shape_Ptr shape = std::make_shared<Sphere>(pos, radius);
	Collision_Ptr actor = std::make_shared<CollisionActor>(shape, CollisionActorType::JUSTAVOID);
	actor->set_update([&](float deltaTime, Shape_Ptr _shape)
	{
		float radius = 1.5f;
		GSvector3 pos(_transform.getPosition());
		pos.y += 1.0f;
		_shape->transfer(pos);
	});

	actor->set_collision_enter([=](Actor* _actor, CollisionActorType _type)
	{
		m_justAvoidFlg = true;
	});
	actor->set_dead([=]()->bool {return isjustTimeEnd(); });
	actor->set_draw([](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer); });
	_group->add(actor);
}

