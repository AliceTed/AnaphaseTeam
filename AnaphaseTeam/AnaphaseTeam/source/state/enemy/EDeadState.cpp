#include "../../../header/state/enemy/EDeadState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"

Enemy::EDeadState::EDeadState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EDeadState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DEAD),false);
}

void Enemy::EDeadState::action(float deltaTime)
{
	m_actor->m_alpha -= 1 / m_actor->m_animatorOne.getCurrentAnimationEndTime();
	m_actor->m_isDead = m_actor->m_animatorOne.isEndCurrentAnimation();
}

Enemy::EDeadState * Enemy::EDeadState::clone() const
{
	return new EDeadState(*this);
}