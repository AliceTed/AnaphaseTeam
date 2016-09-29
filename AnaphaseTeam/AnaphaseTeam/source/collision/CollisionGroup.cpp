#include "../../header/collision/CollisionGroup.h"

CollisionGroup::CollisionGroup(Actor * _actor)
	: m_actor(_actor), m_container()
{
}

CollisionGroup::~CollisionGroup()
{
}

void CollisionGroup::add(Collision_Ptr _collision)
{
	m_container.emplace_back(_collision);
}

void CollisionGroup::initialize()
{
	m_container.clear();
}

void CollisionGroup::update(float deltaTime)
{
	for_each(m_container, [deltaTime](Collision_Ptr _my) {_my->update(deltaTime);});	
}

void CollisionGroup::remove()
{
	auto itr = std::remove_if(m_container.begin(), m_container.end(), [](Collision_Ptr _my) {return _my->isDead();});
	m_container.erase(itr, m_container.end());
}

void CollisionGroup::collision(CollisionGroup & _group)
{
	for_each(m_container, [&](Collision_Ptr _my)
	{
		for_each(_group.m_container, [&](Collision_Ptr _other)
		{
			collision(_my,_other,_group.m_actor);
		});
	});
}

void CollisionGroup::draw(const Renderer & _renderer)
{
	for_each(m_container, [&](Collision_Ptr _my) {_my->draw(_renderer);});
}

void CollisionGroup::for_each(std::vector<Collision_Ptr>& _vector,std::function<void(Collision_Ptr _collision)> _func)
{
	std::for_each(_vector.begin(), _vector.end(), [&](Collision_Ptr _actor) {_func(_actor);});
}

void CollisionGroup::collision(Collision_Ptr _my, Collision_Ptr _other, Actor* _actor)
{
	if (!_my->isCollision(_other.get()))
	{
		_my->exit(_actor, _other.get());
		_other->exit(m_actor, _my.get());
		return;
	}
	_my->collision(_actor, _other.get());
	_other->collision(m_actor, _my.get());
}
