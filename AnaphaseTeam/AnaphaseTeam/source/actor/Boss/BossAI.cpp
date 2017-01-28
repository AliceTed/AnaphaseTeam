#include "actor\Boss\BossAI.h"

BossAI::BossAI(Boss* _enemy)
	:m_actor(_enemy)
{
}
BossAI::~BossAI()
{

}
void BossAI::initialize()
{
	m_actor->changeState(ACTOR_STATE::BSTAND);
}
void BossAI::think(Player * _player)
{

}