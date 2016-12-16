#include "..\..\header\stage\PhaseManager.h"
#include "../../header/stage/Phase.h"
#include <algorithm>
PhaseManager::PhaseManager()
	:m_container(),
	m_current(nullptr)
{
}

void PhaseManager::add(Phase * _phase)
{
	m_container.emplace_back(PhasePtr(_phase));
}

void PhaseManager::update(float deltaTime, ActorManager & _actors, CameraController& _camera)
{
	m_current->update(deltaTime, _actors,_camera);
	if (m_current->isEnd())
	{
		changeFirst();
	}
}

void PhaseManager::draw(IRenderer * _renderer)
{
	m_current->draw(_renderer);
}

void PhaseManager::changeFirst()
{
	if (isEnd())return;
	auto begin = m_container.begin();
	m_current = *begin;	
	m_current->initialize();
	m_container.erase(begin);
}

const bool PhaseManager::isEnd() const
{
	return m_container.empty();
}
