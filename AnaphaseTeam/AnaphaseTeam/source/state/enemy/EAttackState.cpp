#include "../../../header/state/enemy/EAttackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/math/Random.h"
Enemy::EAttackState::EAttackState(Enemy* _enemy)
	:ActorState(_enemy),m_secoundAttack()
{

}

void Enemy::EAttackState::start()
{
	Math::Random rnd;
	m_secoundAttack = rnd(0, 2) == 0 ? true : false;
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK1);
	m_actor->createAttackCollision();
}

void Enemy::EAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		if (m_secoundAttack)
		{
			m_actor->changeState(ACTOR_STATE::ESECOUNDATTACK);
			return;
		}
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Enemy::EAttackState * Enemy::EAttackState::clone() const
{
	return new EAttackState(*this);
}