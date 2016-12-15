#include "../../../header/state/enemy/EDashFrontState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/math/Random.h"
Enemy::EDashFrontState::EDashFrontState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EDashFrontState::start()
{
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::RUN,true,true,10.f,1.3f);
}

void Enemy::EDashFrontState::action(float deltaTime)
{
	
	if (m_actor->distaceToPlayer() < m_actor->PLAYER_DISTANCE_FAR)
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
		return;
	}
	m_actor->m_transform.translate_front(0.12f);
}

Enemy::EDashFrontState * Enemy::EDashFrontState::clone() const
{
	return new EDashFrontState(*this);
}