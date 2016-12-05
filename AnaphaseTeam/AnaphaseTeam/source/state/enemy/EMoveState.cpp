#include "../../../header/state/enemy/EMoveState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/actor/Player/Player.h"
Enemy::EMoveState::EMoveState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EMoveState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::RUN), true, true);
}

void Enemy::EMoveState::action(float deltaTime)
{
	m_actor->m_transform.translate_front(0.05f);
}

Enemy::EMoveState * Enemy::EMoveState::clone() const
{
	return new EMoveState(*this);
}