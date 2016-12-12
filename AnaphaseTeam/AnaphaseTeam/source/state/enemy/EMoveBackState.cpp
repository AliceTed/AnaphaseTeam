#include "../../../header/state/enemy/EMoveBackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EMoveBackState::EMoveBackState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EMoveBackState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKBACK, true, true);
}

void Enemy::EMoveBackState::action(float deltaTime)
{
	if (m_actor->distaceToPlayer() > m_actor->PLAYER_DISTANCE_NEAR)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	m_actor->m_transform.translate_front(-0.05f);
}

Enemy::EMoveBackState * Enemy::EMoveBackState::clone() const
{
	return new EMoveBackState(*this);
}