#include "../../../header/actor/Boss/BreakPoint.h"
#include "../../../header/collision/CollisionGroup.h"
#include "../../../header/actor/Boss/Boss.h"
#include "../../../header/actor/Player/Player.h"

BreakPoint::BreakPoint(CollisionActorType _type, Element _element)
	:m_color(1, 1, 1, 1),
	m_type(_type),
	m_position(0, 0, 0),
	m_element(_element)
{
}

BreakPoint::~BreakPoint()
{
}
void BreakPoint::lerp(Math::TimeLerpVector<GSvector3>& _lerp, BreakPoint & _end)
{
	_lerp.start(m_position,_end.m_position,0.5f);
}

void BreakPoint::update(float deltaTime,std::vector<GSvector3>& _position)
{
	m_position = _position.at(static_cast<unsigned int>(m_element));
}
void BreakPoint::createCollision(Boss * _parent, Group_Ptr& _group)
{
	shape = std::make_shared<Sphere>(GSvector3(0, 1, 0), 1);
	obj = std::make_shared<CollisionActor>(shape, m_type);
	obj->set_collision_enter([&](Actor* _actor, CollisionActorType _type)
	{
		Player* _player = dynamic_cast<Player*>(_actor);
		if (_player == nullptr)return;
		m_color = GScolor(1, 0, 0, 1);
		_player->buildup();
	});
	obj->set_update([&](float deltaTime, Shape_Ptr _shape) {_shape->transfer(m_position); });
	obj->set_draw([&](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer, m_color); });
	_group->add(obj);
}
void BreakPoint::draw(const Renderer& _renderer)
{
}