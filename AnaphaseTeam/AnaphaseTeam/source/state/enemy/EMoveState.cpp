#include "state/enemy/EMoveState.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "actor/Player/Player.h"
#include "math/Random.h"
Goblin::EMoveState::EMoveState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EMoveState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKFORWORD, true, true);
}

void Goblin::EMoveState::action(float deltaTime)
{
	m_actor->lookAtToPlayer();
	if (m_actor->distaceToPlayer() < m_actor->PLAYER_DISTANCE_NEAR+0.3f)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	m_actor->m_transform.translate_front(0.05f);
}

Goblin::EMoveState * Goblin::EMoveState::clone() const
{
	return new EMoveState(*this);
}