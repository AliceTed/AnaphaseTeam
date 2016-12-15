#include "../../../header/state/enemy/EDamageState.h"

Goblin::EDamageState::EDamageState(Goblin* _enemy)
	:ActorState(_enemy)
{
}

void Goblin::EDamageState::start()
{
}

void Goblin::EDamageState::action(float deltaTime)
{
	m_actor->m_knockBack.update(deltaTime);

	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ESTAND);
	}
	if (m_actor->m_status.getHp() <= 0)
	{
		changeState(ACTOR_STATE::EDEAD);
		m_actor->m_collision.clear();
	}
}

Goblin::EDamageState * Goblin::EDamageState::clone() const
{
	return new EDamageState(*this);
}