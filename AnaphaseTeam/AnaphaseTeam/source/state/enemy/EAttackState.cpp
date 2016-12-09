#include "../../../header/state/enemy/EAttackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EAttackState::EAttackState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EAttackState::start()
{
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK1);
	m_actor->createAttackCollision();
}

void Enemy::EAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Enemy::EAttackState * Enemy::EAttackState::clone() const
{
	return new EAttackState(*this);
}