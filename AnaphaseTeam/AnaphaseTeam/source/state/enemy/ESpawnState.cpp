#include "../../../header/state/enemy/ESpawnState.h"

Enemy::ESpawnState::ESpawnState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::ESpawnState::start()
{
}

void Enemy::ESpawnState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ESTAND);
	}
}

Enemy::ESpawnState * Enemy::ESpawnState::clone() const
{
	return new ESpawnState(*this);
}