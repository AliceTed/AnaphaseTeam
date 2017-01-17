#include "state/enemy/OverNearAI.h"
OverNearAI::OverNearAI(Goblin* _enemy)
	:m_actor(_enemy)
{

}
OverNearAI::~OverNearAI()
{}
void OverNearAI::initialize()
{
	m_actor->changeState(ACTOR_STATE::ETHINK);
}
void OverNearAI::think(Player * _player)
{
	if (m_actor->isBlocked())
	{
		m_actor->changeState(ACTOR_STATE::ESLIDE);
	}
	m_actor->changeState(ACTOR_STATE::EMOVEBACK);
}