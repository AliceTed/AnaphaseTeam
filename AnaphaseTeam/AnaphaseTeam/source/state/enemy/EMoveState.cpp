#include "../../../header/state/enemy/EMoveState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/math/Random.h"
Enemy::EMoveState::EMoveState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EMoveState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKFORWORD, true, true);
}

void Enemy::EMoveState::action(float deltaTime)
{
	if (m_actor->distaceToPlayer() < m_actor->PLAYER_DISTANCE_NEAR+0.3f)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	m_actor->m_transform.translate_front(0.05f);
}

Enemy::EMoveState * Enemy::EMoveState::clone() const
{
	return new EMoveState(*this);
}