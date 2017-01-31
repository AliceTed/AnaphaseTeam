#include "state/enemy/ESecoundAttackState.h"
#include "data/id/ENEMY_ANIMATION.h"
Goblin::ESecoundAttackState::ESecoundAttackState(Goblin* _enemy)
	:ActorState(_enemy), m_timer(0.0f), funcPtr(nullptr)
{

}

void Goblin::ESecoundAttackState::start()
{
	m_timer.initialize();
	m_timer.setEndTime(0.7f);
	funcPtr = std::bind(&Goblin::ESecoundAttackState::collisionStart, this, std::placeholders::_1);
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK2);
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENEMY_ATTACK);
}

void Goblin::ESecoundAttackState::action(float deltaTime)
{
	funcPtr(deltaTime);
}

void Goblin::ESecoundAttackState::collisionStart(float deltaTime)
{
	m_timer.update(deltaTime);
	if (m_timer.isEnd())
	{
		m_actor->createAttackCollision();
		funcPtr = std::bind(&Goblin::ESecoundAttackState::finishAction, this, std::placeholders::_1);
	}
}

void Goblin::ESecoundAttackState::finishAction(float deltaTime)
{
	if (!m_actor->m_animatorOne.isEndCurrentAnimation())
		return;
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENEMY_ATTACK);
	m_actor->changeState(ACTOR_STATE::ETHINK);
}

Goblin::ESecoundAttackState * Goblin::ESecoundAttackState::clone() const
{
	return new ESecoundAttackState(*this);
}