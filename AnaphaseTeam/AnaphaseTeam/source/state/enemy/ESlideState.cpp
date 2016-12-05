#include "../../../header/state/enemy/ESlideState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"

Enemy::ESlideState::ESlideState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::ESlideState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::SLIDE), true, true);
}

void Enemy::ESlideState::action(float deltaTime)
{
}

Enemy::ESlideState * Enemy::ESlideState::clone() const
{
	return new ESlideState(*this);
}