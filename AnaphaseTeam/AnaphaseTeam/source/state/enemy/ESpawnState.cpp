#include "../../../header/state/enemy/ESpawnState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::ESpawnState::ESpawnState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::ESpawnState::start()
{
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::SCREAM);
}

void Enemy::ESpawnState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Enemy::ESpawnState * Enemy::ESpawnState::clone() const
{
	return new ESpawnState(*this);
}