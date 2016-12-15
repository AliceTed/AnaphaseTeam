#include "..\..\..\header\state\enemy\OverFarAI.h"
#include "../../../header/math/Random.h"
OverFarAI::OverFarAI(Enemy * _actor)
	:m_actor(_actor)
{
}

OverFarAI::~OverFarAI()
{
}

void OverFarAI::initialize()
{
	m_actor->changeState(ACTOR_STATE::ETHINK);
}

void OverFarAI::think(Player * _player)
{
	//*****************�����i��j**********************************
	//*****************���\����**********************
	Math::Random rnd;
	int act = rnd(0, 10);
	if (act % 10 == 0)
	{
		if (m_actor->requestDistance(EAI::MIDDRANGE))
			return;
		m_actor->changeState(ACTOR_STATE::EDASH);
		return;

	}
	if (act % 2 == 1)
	{
		m_actor->changeState(ACTOR_STATE::ESLIDE);
		return;
	}
	m_actor->changeState(ACTOR_STATE::ESTAND);
}
