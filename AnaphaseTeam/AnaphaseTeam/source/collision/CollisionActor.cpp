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
	//過去にあるか
	if (is_find(m_previous, _other))
	{
		if (m_collision_stay == nullptr)return;
		m_collision_stay(_otherActor, _other->m_type);
		return;
	}
	//過去になかったら
	//登録と呼び出し
	std::shared_ptr<CollisionActor> actor = std::make_shared<CollisionActor>(*_other);
	m_previous.emplace_back(actor);
	if (m_collision_enter == nullptr)return;
	m_collision_enter(_otherActor, _other->m_type);
}

void CollisionActor::exit(Actor * _otherActor, CollisionActor * _other)
{
	//過去にあるか確認しあったら削除と呼び出し
	auto itr=std::remove_if(m_previous.begin(), m_previous.end(), [&_other](std::shared_ptr<CollisionActor> _actor)->bool
	{
		return  _other==_actor.get();
	});
	//なかったら
	if (itr == m_previous.end())return;

	m_previous.erase(itr,m_previous.end());
	if (m_collision_exit == nullptr)return;
	m_collision_exit(_otherActor, _other->m_type);
}

void CollisionActor::draw(const Renderer & _renderer)
{
	if (m_draw == nullptr)return;
	m_draw(_renderer);
}

const bool CollisionActor::isDead() const
{
	if (m_destroy == nullptr)return true;
	return m_destroy();
}

void CollisionActor::set_dead(const std::function<const bool()>& _function)
{
	m_destroy = _function;
}
void CollisionActor::set_update(const std::function<void(float, Shape_Ptr)>& _function)
{
	m_update = _function;
}
void CollisionActor::set_draw(const std::function<void(const Renderer& _renderer)>& _function)
{
	m_draw = _function;
}
void CollisionActor::set_collision_enter(const std::function<void(Actor*, CollisionActorType)>& _function)
{
	m_collision_enter = _function;
}
void CollisionActor::set_collision_stay(const std::function<void(Actor*, CollisionActorType)>& _function)
{
	m_collision_stay = _function;
}
void CollisionActor::set_collision_exit(const std::function<void(Actor*, CollisionActorType)>& _function)
{
	m_collision_exit = _function;
}

const bool CollisionActor::is_find(std::vector<std::shared_ptr<CollisionActor>>& _container, CollisionActor * _other)
{
	bool is_any = std::any_of(_container.begin(), _container.end(),
		[&_other](std::shared_ptr<CollisionActor> _actor)
	{
		return _actor.get() == _other;
	});
	return is_any;
}
