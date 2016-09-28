#include "../../header/collision/TestCollisionManager.h"

TestCollisionManager::TestCollisionManager()
	:m_container()
{
}

TestCollisionManager::~TestCollisionManager()
{
}

void TestCollisionManager::add(Group_Ptr _group)
{
	m_container.emplace_back(_group);
}

void TestCollisionManager::initialize()
{
	m_container.clear();
}

void TestCollisionManager::update(float deltaTime)
{
	std::for_each(m_container.begin(),m_container.end(),[deltaTime](Group_Ptr _group){_group->update(deltaTime);});
	for (Group_Itr first = m_container.begin(); first != m_container.end();++first)
	{
		for (Group_Itr second = ++first; second != m_container.end(); ++second)
		{
			(*first)->collision(*(*second).get());
		}
	}
}

void TestCollisionManager::draw(const Renderer & _renderer)
{
	std::for_each(m_container.begin(), m_container.end(), [&_renderer](Group_Ptr _group) {_group->draw(_renderer);});
}
