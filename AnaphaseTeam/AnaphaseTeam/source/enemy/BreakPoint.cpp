#include "../../header/enemy/BreakPoint.h"
#include "../../header/collision/CollisionMediator.h"
#include "../../header/actor/TestActor.h"
#include "../../header/actor/Player/Player.h"
BreakPoint::BreakPoint(const Sphere& _sphere,CollisionType _type)
	:m_sphere(_sphere), m_color(1, 1, 1, 1),m_type(_type),m_mode(BreakMode::Non)
	, m_delay(2.0f)
{
}

BreakPoint::~BreakPoint()
{
}

void BreakPoint::damage(Player* _player)
{
	if (m_mode == BreakMode::Non)
	{
		m_color = GScolor(1, 0, 0, 1);
		m_mode = BreakMode::Possible;
		m_delay.initialize();
	}
	if (m_mode == BreakMode::Possible&&m_delay.isEnd())
	{
		m_color = GScolor(1, 1, 0, 1);
		m_mode = BreakMode::Break;
		_player->buildup();
	}
}
void BreakPoint::update(float deltaTime, const GSvector3 & _position)
{
	m_sphere.transfer(_position);
	if (m_mode == BreakMode::Possible)
	{
		m_delay.update(deltaTime);
	}
}
void BreakPoint::createCollision(TestActor * _parent, CollisionMediator * _mediator)
{
	Shape_Ptr shape = std::make_shared<Sphere>(m_sphere);
	Obj_Ptr obj = std::make_shared<CollisionObject>(_parent, shape, m_type,
		[&](Actor* _parent, CollisionType _type)
	{
		if (_type != CollisionType::PLAYER_ATTACK)return;
		Player* _player = dynamic_cast<Player*>(_parent);
		if (_player == nullptr)return;
		damage(_player);
	});
	_mediator->add(obj);
}
void BreakPoint::draw(const Renderer& _renderer)
{
	m_sphere.draw(_renderer,m_color);
}

const bool BreakPoint::isBreak() const
{
	return m_mode==BreakMode::Break;
}
