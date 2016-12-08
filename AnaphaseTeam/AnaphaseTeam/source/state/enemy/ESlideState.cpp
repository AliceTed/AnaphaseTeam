#include "../../../header/state/enemy/ESlideState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/actor/Player/Player.h"
Enemy::ESlideState::ESlideState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::ESlideState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WORKLEFT, true, true);
}

void Enemy::ESlideState::action(float deltaTime)
{
	m_actor->m_transform.translate_left(0.03f);
}

Enemy::ESlideState * Enemy::ESlideState::clone() const
{
	return new ESlideState(*this);
}