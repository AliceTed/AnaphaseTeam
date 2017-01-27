#include "..\..\..\header\state\enemy\NearAI.h"
#include "math/Random.h"
NearAI::NearAI(Goblin* _enemy) :
	m_actor(_enemy)
{

}

NearAI::~NearAI()
{
}

void NearAI::initialize()
{
	m_actor->changeState(ACTOR_STATE::ETHINK);
}

void NearAI::think(Player * _player)
{
	//*****************‹——£i¬j**********************************
	//*****************‚¨ŒÝ‚¢‚ÌUŒ‚‚ª“–‚½‚é”ÍˆÍ**********************
	Math::Random rnd;
	int act = rnd(0, 4);
	if (act ==0)
	{
		m_actor->changeState(ACTOR_STATE::ESLIDE);
		return;
	}
	if (act== 1)
	{
		m_actor->changeState(ACTOR_STATE::EATTACK);
		return;
	}
	m_actor->changeState(ACTOR_STATE::ESTAND);
}
