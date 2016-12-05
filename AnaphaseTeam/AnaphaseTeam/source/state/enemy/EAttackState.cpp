#include "../../../header/state/enemy/EAttackState.h"

Enemy::EAttackState::EAttackState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EAttackState::start()
{
}

void Enemy::EAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		//m_state = ESTATE::STAND;
		m_actor->changeState(ACTOR_STATE::ESTAND);
	}
}

Enemy::EAttackState * Enemy::EAttackState::clone() const
{
	return new EAttackState(*this);
}