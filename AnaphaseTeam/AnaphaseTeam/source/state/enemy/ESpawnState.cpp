#include "../../../header/state/enemy/ESpawnState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Goblin::ESpawnState::ESpawnState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::ESpawnState::start()
{
	m_actor->lookAtToPlayer();
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::SCREAM);
}

void Goblin::ESpawnState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Goblin::ESpawnState * Goblin::ESpawnState::clone() const
{
	return new ESpawnState(*this);
}