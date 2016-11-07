#include "../../header/collision/CollisionActor.h"


CollisionActor::CollisionActor(Shape_Ptr _shape, CollisionActorType _type)
	:m_hit(),
	m_shape(_shape),
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
	remove([](CollisionActor* _actor)->bool {return _actor->isDead();});
	if (m_update == nullptr)return;
	m_update(deltaTime, m_shape);
}

const bool CollisionActor::isCollision(CollisionActor * _other) 
{
	return _other->m_shape->isCollision(m_shape.get(),&m_hit);
}

void CollisionActor::collision(Actor * _otherActor, CollisionActor * _other)
{
	//‰ß‹Ž‚É‚ ‚é‚©
	if (is_find(m_previous, _other))
	{
		if (m_collision_stay == nullptr)return;
		m_hit.m_paremt = _otherActor;
		m_hit.m_type = _other->m_type;
		m_collision_stay(&m_hit);
		return;
	}
	m_previous.emplace_back(_other);
	if (m_collision_enter == nullptr)return;
	m_hit.m_paremt = _otherActor;
	m_hit.m_type = _other->m_type;
	m_collision_enter(&m_hit);
}

void CollisionActor::exit(Actor * _otherActor, CollisionActor * _other)
{
	//íœ‚µ‚½‚©
	bool isremove = remove([&_other](CollisionActor* _actor)->bool {return _other == _actor;});
	if (!isremove)return;
	if (m_collision_exit == nullptr)return;
	m_hit.m_paremt = _otherActor;
	m_hit.m_type = _other->m_type;
	m_collision_exit(&m_hit);
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
void CollisionActor::set_update(std::function<void(float, Shape_Ptr)> _function)
{
	m_update = _function;
}
void CollisionActor::set_draw(std::function<void(const Renderer&, Shape_Ptr)> _function)
{
	m_draw = _function;
}
void CollisionActor::set_collision_enter(std::function<void(Hit*)> _function)
{
	m_collision_enter = _function;
}
void CollisionActor::set_collision_stay(std::function<void(Hit*)> _function)
{
	m_collision_stay = _function;
}
void CollisionActor::set_collision_exit(std::function<void(Hit*)> _function)
{
	m_collision_exit = _function;
}

const bool CollisionActor::is_find(std::vector<CollisionActor*>& _container, CollisionActor * _other)
{
	return std::any_of(_container.begin(), _container.end(),
		[&_other](CollisionActor* _actor)
	{
		return _other == _actor;
	});
}
const bool CollisionActor::remove(std::function<bool(CollisionActor*)> function)
{
	auto itr = std::remove_if(m_previous.begin(), m_previous.end(), function);
	if (itr == m_previous.end())return false;
	m_previous.erase(itr);
	return true;
}
