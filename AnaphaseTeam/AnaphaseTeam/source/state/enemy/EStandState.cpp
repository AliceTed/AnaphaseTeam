#include "../../../header/state/enemy/EStandState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EStandState::EStandState(Enemy* _enemy)
	:ActorState(_enemy), m_tiemr(2.0f)
{

}

void Enemy::EStandState::start()
{
	m_tiemr.initialize();
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::STAND, true, true);
}

void Enemy::EStandState::action(float deltaTime)
{
	m_tiemr.update(deltaTime);
	if (m_tiemr.isEnd())
	{
		changeState(ACTOR_STATE::ETHINK);
	}
}

Enemy::EStandState * Enemy::EStandState::clone() const
{
	return new EStandState(*this);
}