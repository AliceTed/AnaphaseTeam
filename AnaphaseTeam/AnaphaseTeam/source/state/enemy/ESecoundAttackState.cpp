#include "../../../header/state/enemy/ESecoundAttackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::ESecoundAttackState::ESecoundAttackState(Enemy* _enemy)
	:ActorState(_enemy), m_start(false), m_timer(0)
{

}

void Enemy::ESecoundAttackState::start()
{
	m_start = true;
	m_timer = 0;
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK2);
	m_actor->createAttackCollision();
}

void Enemy::ESecoundAttackState::action(float deltaTime)
{
	m_start = m_timer > 10 ? false : m_start;
	if (m_start)
	{
		m_timer += 1 * deltaTime;
		return;
	}
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}

	
}

Enemy::ESecoundAttackState * Enemy::ESecoundAttackState::clone() const
{
	return new ESecoundAttackState(*this);
}