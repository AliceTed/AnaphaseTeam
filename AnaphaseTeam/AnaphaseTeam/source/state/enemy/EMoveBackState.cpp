#include "state/enemy/EMoveBackState.h"
#include "data/id/ENEMY_ANIMATION.h"
Goblin::EMoveBackState::EMoveBackState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EMoveBackState::start()
{
	if (!m_actor->m_isBlock)
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKBACK, true, true);
}

void Goblin::EMoveBackState::action(float deltaTime)
{
	m_actor->lookAtToPlayer();
	if (m_actor->distaceToPlayer() > m_actor->PLAYER_DISTANCE_NEAR)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	if (m_actor->m_isBlock)
	{
		m_actor->changeState(ACTOR_STATE::ESLIDE);
		return;
	}
	m_actor->m_transform.translate_front(-0.05f);
}

Goblin::EMoveBackState * Goblin::EMoveBackState::clone() const
{
	return new EMoveBackState(*this);
}