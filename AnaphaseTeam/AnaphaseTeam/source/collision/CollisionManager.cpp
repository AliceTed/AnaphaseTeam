#include "../../header/collision/CollisionManager.h"

CollisionManager::CollisionManager()
	:m_container()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::add(Group_Ptr _group)
{
	m_container.emplace_back(_group);
}

void CollisionManager::initialize()
{
	m_container.clear();
}

void CollisionManager::update(float deltaTime)
{
	for (auto& i:m_container){i->update(deltaTime);}
	collision();
}

void CollisionManager::draw(const Renderer & _renderer)
{
	for (auto& i : m_container) { i->draw(_renderer); }
}

void CollisionManager::collision()
{
	for (Group_Itr first = m_container.begin(); first != m_container.end();++first)
	{
		Group_Itr second = first;
		for (++second; second != m_container.end(); ++second)
		{
			(*first)->collision(*(*second).get());
		}
	}
}
