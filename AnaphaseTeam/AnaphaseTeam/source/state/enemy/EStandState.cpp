#include "../../../header/state/enemy/EStandState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Goblin::EStandState::EStandState(Goblin* _enemy)
	:ActorState(_enemy), m_tiemr(1.5f)
{

}

void Goblin::EStandState::start()
{
	m_tiemr.initialize();
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::STAND, true, true);
}

void Goblin::EStandState::action(float deltaTime)
{
	//m_actor->directionToPlayer();
	m_tiemr.update(deltaTime);
	if (m_tiemr.isEnd())
	{
		changeState(ACTOR_STATE::ETHINK);
	}
}

Goblin::EStandState * Goblin::EStandState::clone() const
{
	return new EStandState(*this);
}