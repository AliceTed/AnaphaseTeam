#include "state\boss\BStandState.h"
#include "data\id\ENEMY_ANIMATION.h"
Boss::BStandState::BStandState(Boss* _actor)
	:ActorState(_actor) 
{

}


void Boss::BStandState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::STAND,true,true);
}
void Boss::BStandState::action(float deltatime)
{

}
Boss::BStandState* Boss::BStandState::clone()const
{
	return new BStandState(*this);
}