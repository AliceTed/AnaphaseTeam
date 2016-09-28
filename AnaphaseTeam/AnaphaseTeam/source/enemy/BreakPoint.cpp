#include "../../header/enemy/BreakPoint.h"
#include "../../header/collision/CollisionGroup.h"
#include "../../header/actor/TestActor.h"
#include "../../header/actor/Player/Player.h"
BreakPoint::BreakPoint(const Sphere& _sphere, CollisionActorType _type)
	:m_sphere(_sphere), m_color(1, 1, 1, 1), m_type(_type), m_mode(BreakMode::Non)
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
	}
	if (m_mode == BreakMode::Possible)
	{
		m_color = GScolor(1, 1, 0, 1);
		m_mode = BreakMode::Break;
		_player->buildup();
	}
}
void BreakPoint::update(float deltaTime, const GSvector3 & _position)
{
	m_sphere.transfer(_position);
}
void BreakPoint::createCollision(TestActor * _parent, Group_Ptr& _group)
{
	Shape_Ptr shape = std::make_shared<Sphere>(GSvector3(0, 1, 0), 1);
	Collision_Ptr obj = std::make_shared<CollisionActor>(shape, m_type);
	obj->set_collision_enter([&](Actor* _actor, CollisionActorType _type)
	{
		if (_type == CollisionActorType::PLAYER)
		{
			m_color = GScolor(1, 0, 0, 1);
		}
	});
	obj->set_collision_stay([&](Actor* _actor, CollisionActorType _type)
	{
		if (_type == CollisionActorType::PLAYER)
		{
			m_color = GScolor(0, 0, 0, 1);
		}
	});
	obj->set_collision_exit([&](Actor* _actor, CollisionActorType _type)
	{
		if (_type != CollisionActorType::PLAYER)return;

		Player* _player = dynamic_cast<Player*>(_actor);
		if (_player == nullptr)return;
		m_color = GScolor(1, 1, 0, 1);
		_player->buildup();

	});
	obj->set_draw([](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer);});
	_group->add(obj);
}
void BreakPoint::draw(const Renderer& _renderer)
{
	m_sphere.draw(_renderer, m_color);
}

const bool BreakPoint::isBreak() const
{
	return m_mode == BreakMode::Break;
}
