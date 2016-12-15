#include "../../../header/state/enemy/EMoveBackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Goblin::EMoveBackState::EMoveBackState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EMoveBackState::start()
{
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
	m_actor->m_transform.translate_front(-0.05f);
}

Goblin::EMoveBackState * Goblin::EMoveBackState::clone() const
{
	return new EMoveBackState(*this);
}