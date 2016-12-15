#include "../../../header/state/enemy/MiddleRangeAI.h"
#include "../../../header/math/Random.h"
MiddleRangeAI::MiddleRangeAI(Enemy* _actor) :
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
	//*****************‹——£i’†j**********************************
	//*****************‚¿‚å‚Á‚Æ‰“‚¢‚Æ‚±‚ë**********************
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