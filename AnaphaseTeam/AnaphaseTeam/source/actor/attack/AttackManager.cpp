#include "../../../header/actor/attack/attackManager.h"
#include "../../../header/actor/Player/Player.h"
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

void attackManager::update(Player* _player)
{
	scytheAttack(_player);
}

void attackManager::scytheAttack(Player* _player)
{
	if (m_Input->scytheTrigger())
		_player->scythAttack();
}

