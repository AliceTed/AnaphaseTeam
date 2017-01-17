#include "state/enemy/EnemyAIController.h"
EnemyAIController::EnemyAIController():
m_aicontainer(),m_currentKey(EAI::ATTACKRANGE)
{

}
EnemyAIController::~EnemyAIController()
{

}
void EnemyAIController::initialize()
{
	m_aicontainer.clear();
}
void EnemyAIController::think(Player* _player)
{
	m_aicontainer.at(m_currentKey)->think(_player);
}
void EnemyAIController::add(EAI _key, AI_Ptr _ai)
{
	m_aicontainer[_key] = _ai;
}

void EnemyAIController::change(EAI _key)
{
	if (m_currentKey == _key)return;
	m_currentKey = _key;
	m_aicontainer.at(m_currentKey)->initialize();
}

EAI EnemyAIController::currentRange()
{
	return m_currentKey;
}
