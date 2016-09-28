#include "../../header/collision/CollisionActor.h"


CollisionActor::CollisionActor(Shape_Ptr _shape, CollisionActorType _type)
	:m_shape(_shape),
	m_type(_type),
	m_previous(),
	m_destroy(nullptr),
	m_update(nullptr),
	m_draw(nullptr),
	m_collision_enter(nullptr),
	m_collision_stay(nullptr),
	m_collision_exit(nullptr)
{
}

CollisionActor::~CollisionActor()
{
}

void CollisionActor::update(float deltaTime)
{
	if (m_update == nullptr)return;
	m_update(deltaTime, m_shape);
}

const bool CollisionActor::isCollision(CollisionActor * _other) const
{
	return _other->m_shape->isCollision(m_shape.get());
}

void CollisionActor::collision(Actor * _otherActor, CollisionActor * _other)
{
	//‰ß‹Ž‚É‚ ‚é‚©
	if (is_find(m_previous, _other))
	{
		if (m_collision_stay == nullptr)return;
		m_collision_stay(_otherActor, _other->m_type);
		return;
	}
	//‰ß‹Ž‚É‚È‚©‚Á‚½‚ç
	//“o˜^‚ÆŒÄ‚Ño‚µ
	m_previous.emplace_back(_other);
	if (m_collision_enter == nullptr)return;
	m_collision_enter(_otherActor, _other->m_type);
}

void CollisionActor::exit(Actor * _otherActor, CollisionActor * _other)
{

	//‰ß‹Ž‚É‚ ‚é‚©Šm”F‚µ‚ ‚Á‚½‚çíœ‚ÆŒÄ‚Ño‚µ
	auto itr = std::remove_if(m_previous.begin(), m_previous.end(), [&_other](CollisionActor* _actor)->bool
	{
		return  _other == _actor;
	});
	//‚È‚©‚Á‚½‚ç
	if (itr == m_previous.end())return;

	m_previous.erase(itr, m_previous.end());
	if (m_collision_exit == nullptr)return;
	m_collision_exit(_otherActor, _other->m_type);
}
#include "../../header/renderer/Renderer.h"
void CollisionActor::draw(const Renderer & _renderer)
{
	_renderer.getDraw2D().string(std::to_string(m_previous.size()), &GSvector2(0, 0), 20);
	if (m_draw == nullptr)return;
	m_draw(_renderer, m_shape);
}

const bool CollisionActor::isDead() const
{
	if (m_destroy == nullptr)return false;
	return m_destroy();
}

void CollisionActor::set_dead(std::function<const bool()> _function)
{
	m_destroy = _function;
}
void CollisionActor::set_update( std::function<void(float, Shape_Ptr)> _function)
{
	m_update = _function;
}
void CollisionActor::set_draw(std::function<void(const Renderer&, Shape_Ptr)> _function)
{
	m_draw = _function;
}
void CollisionActor::set_collision_enter(std::function<void(Actor*, CollisionActorType)> _function)
{
	m_collision_enter = _function;
}
void CollisionActor::set_collision_stay(std::function<void(Actor*, CollisionActorType)> _function)
{
	m_collision_stay = _function;
}
void CollisionActor::set_collision_exit( std::function<void(Actor*, CollisionActorType)> _function)
{
	m_collision_exit = _function;
}

const bool CollisionActor::is_find(std::vector<CollisionActor*>& _container, CollisionActor * _other)
{
	bool is_any = std::any_of(_container.begin(), _container.end(),
		[&_other](CollisionActor* _actor)
	{
		return _other==_actor;
	});
	return is_any;
}
