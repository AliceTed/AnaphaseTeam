#include "state/enemy/EDeadState.h"
#include "data/id/ENEMY_ANIMATION.h"

Goblin::EDeadState::EDeadState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EDeadState::start()
{
	m_actor->scoreDead();

	if (m_actor->blowDead())
	{
		m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DIE2);
		return;
	}
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::DIE1);
}

void Goblin::EDeadState::action(float deltaTime)
{
	if (m_actor->blowDead())
	{
		m_actor->m_knockBack.update(deltaTime);
	}
	m_actor->m_alpha -= 0.02f;
	m_actor->m_isDead = m_actor->m_animatorOne.isEndCurrentAnimation();
}

Goblin::EDeadState * Goblin::EDeadState::clone() const
{
	return new EDeadState(*this);
}