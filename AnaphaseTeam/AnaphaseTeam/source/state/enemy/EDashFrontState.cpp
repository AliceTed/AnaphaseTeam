#include "state/enemy/EDashFrontState.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "math/Random.h"
Goblin::EDashFrontState::EDashFrontState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EDashFrontState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::RUN,true,true,10.f,1.3f);
}

void Goblin::EDashFrontState::action(float deltaTime)
{
	m_actor->lookAtToPlayer();
	if (m_actor->distaceToPlayer() < m_actor->PLAYER_DISTANCE_FAR)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	m_actor->m_transform.translate_front(0.12f);
}

Goblin::EDashFrontState * Goblin::EDashFrontState::clone() const
{
	return new EDashFrontState(*this);
}