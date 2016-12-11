#include "../../../header/state/enemy/OverNearAI.h"
OverNearAI::OverNearAI(Enemy* _enemy)
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
	m_actor->changeState(ACTOR_STATE::EMOVEBACK);
}