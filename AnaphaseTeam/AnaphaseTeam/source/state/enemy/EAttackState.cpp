#include "../../../header/state/enemy/EAttackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EAttackState::EAttackState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EAttackState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::ATTACK), true, false, false, 1.0f);
	m_actor->createAttackCollision();
}

void Enemy::EAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ESTAND);
	}
}

Enemy::EAttackState * Enemy::EAttackState::clone() const
{
	return new EAttackState(*this);
}