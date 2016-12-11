#include "../../../header/state/enemy/EDashFrontState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EDashFrontState::EDashFrontState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EDashFrontState::start()
{
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::RUN);
}

void Enemy::EDashFrontState::action(float deltaTime)
{
}

Enemy::EDashFrontState * Enemy::EDashFrontState::clone() const
{
	return new EDashFrontState(*this);
}