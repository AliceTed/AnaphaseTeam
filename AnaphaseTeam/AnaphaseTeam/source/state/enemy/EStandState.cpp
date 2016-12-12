#include "../../../header/state/enemy/EStandState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EStandState::EStandState(Enemy* _enemy)
	:ActorState(_enemy), m_tiemr(4.0f)
{

}

void Enemy::EStandState::start()
{
	m_tiemr.initialize();
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::STAND), true, true);
}

void Enemy::EStandState::action(float deltaTime)
{
	m_tiemr.update(deltaTime);
	if (m_tiemr.isEnd())
	{
		if (!m_actor->m_isGround)
		{
			changeState(ACTOR_STATE::EMOVE);
		}	
	}
}

Enemy::EStandState * Enemy::EStandState::clone() const
{
	return new EStandState(*this);
}