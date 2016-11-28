#include "../../header/collision/CollisionGroup.h"
#include "../../header/collision/HitInformation.h"
#include <algorithm>
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
	for (auto& i: m_container){i->update(deltaTime);}
	remove();
}

void CollisionGroup::remove()
{
	auto itr = std::remove_if(m_container.begin(), m_container.end(), [](Collision_Ptr& _actor) {return _actor->isDead();});
	m_container.erase(itr, m_container.end());
}

void CollisionGroup::collision(CollisionGroup & _group)
{
	for (auto& act1 : m_container)
	{
		for (auto& act2 : _group.m_container)
		{
			collision(act1,act2, _group.m_actor);
		}
	}
}

void CollisionGroup::draw(const Renderer & _renderer)
{
	for (auto& i : m_container){i->draw(_renderer);}
}
void CollisionGroup::clear()
{
	for (auto& i : m_container) { i->destroy(); }
}
unsigned int CollisionGroup::size() const
{
	return m_container.size();
}
void CollisionGroup::collision(Collision_Ptr& _my, Collision_Ptr& _other, Actor* _actor)
{
	HitInformation info1(m_actor);
	HitInformation info2(_actor);

	if (!_my->isCollision(_other,&info1,&info2))
	{
		_my->exit(_other,info2);
		_other->exit(_my,info1);
		return;
	}
	_my->collision(_other, info2);
	_other->collision(_my, info1);
}
