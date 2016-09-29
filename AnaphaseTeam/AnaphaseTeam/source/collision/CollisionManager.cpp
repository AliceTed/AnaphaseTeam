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
	std::for_each(m_container.begin(),m_container.end(),[deltaTime](Group_Ptr _group){_group->update(deltaTime);});
	std::for_each(m_container.begin(), m_container.end(), [](Group_Ptr _group) {_group->remove();});
	for (Group_Itr first = m_container.begin(); first != m_container.end();++first)
	{
		Group_Itr second = first;
		for (++second; second != m_container.end(); ++second)
		{
			(*first)->collision(*(*second).get());
		}
	}
}

void CollisionManager::draw(const Renderer & _renderer)
{
	std::for_each(m_container.begin(), m_container.end(), [&_renderer](Group_Ptr _group) {_group->draw(_renderer);});
}
