#include "../../../header/state/enemy/EStandState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"

Enemy::EStandState::EStandState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EStandState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::STAND), true, true);
}

void Enemy::EStandState::action(float deltaTime)
{
	m_actor->m_stay_timer.update(deltaTime);
}

Enemy::EStandState * Enemy::EStandState::clone() const
{
	return new EStandState(*this);
}