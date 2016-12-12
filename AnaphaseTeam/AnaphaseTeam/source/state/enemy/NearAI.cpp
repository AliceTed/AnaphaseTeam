#include "..\..\..\header\state\enemy\NearAI.h"
#include "../../../header/math/Random.h"
NearAI::NearAI(Enemy* _enemy) :
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
	if (act %3==0)
	{
		m_actor->changeState(ACTOR_STATE::ESTAND);
		return;
	}
	if (act %3== 1)
	{
		m_actor->changeState(ACTOR_STATE::EATTACK);
		return;
	}
	m_actor->changeState(ACTOR_STATE::ESLIDE);
}
