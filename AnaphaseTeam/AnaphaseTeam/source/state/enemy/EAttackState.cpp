#include "../../../header/state/enemy/EAttackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/math/Random.h"
Goblin::EAttackState::EAttackState(Goblin* _enemy)
	:ActorState(_enemy),m_secoundAttack()
{

}

void Goblin::EAttackState::start()
{
	m_actor->lookAtToPlayer();
	Math::Random rnd;
	m_secoundAttack = rnd(0, 2) == 0 ? true : false;
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK1);
	m_actor->createAttackCollision();
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENEMY_ATTACK);
}

void Goblin::EAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		GameDevice::getInstacnce().sound().stopSE(SE_ID::ENEMY_ATTACK);
		if (m_secoundAttack)
		{
			m_actor->changeState(ACTOR_STATE::ESECOUNDATTACK);
			return;
		}
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Goblin::EAttackState * Goblin::EAttackState::clone() const
{
	return new EAttackState(*this);
}