#include "attackManager.h"

attackManager::attackManager()
	:m_Scythe(/*MODEL_ID::PLAYER*/),
	m_Gun(/*MODEL_ID::PLAYER*/)
{
}

attackManager::~attackManager()
{
}

void attackManager::initialize()
{
	m_Scythe.initialize();
	m_Gun.initialize();
}

void attackManager::update()
{
	scytheAttack();
	gunAttack();
}

bool attackManager::scytheAttack()
{
	if (m_Input->scytheTrigger())
	{
		m_Scythe.update();
	}
	return m_Input->scytheTrigger();
}

bool attackManager::gunAttack()
{
	if (m_Input->gunTrigger())
	{
		m_Gun.update();
	}
	return m_Input->gunTrigger();
}
