#include "state/enemy/MiddleRangeAI.h"
#include "math/Random.h"
MiddleRangeAI::MiddleRangeAI(Goblin* _actor) :
	m_actor(_actor)
{

}

MiddleRangeAI::~MiddleRangeAI()
{
}

void MiddleRangeAI::initialize()
{
	m_actor->changeState(ACTOR_STATE::ETHINK);
}
void MiddleRangeAI::think(Player * _player)
{
	//*****************�����i���j**********************************
	//*****************������Ɖ����Ƃ���**********************
	Math::Random rnd;
	int act = rnd(0, 10);
	if (act % 10 == 0)
	{
		if (m_actor->requestDistance(EAI::ATTACKRANGE))
			return;
		m_actor->changeState(ACTOR_STATE::EMOVE);
		return;
	}
	if (act % 2 == 1)
	{
		m_actor->changeState(ACTOR_STATE::ESLIDE);
		return;
	}
	m_actor->changeState(ACTOR_STATE::ESTAND);
}