#include "../../../header/state/enemy/EDamageState.h"

Enemy::EDamageState::EDamageState(Enemy* _enemy)
	:ActorState(_enemy), m_gravity(0.0f)
{
}

void Enemy::EDamageState::start()
{
	m_gravity = 0.0f;
}

void Enemy::EDamageState::action(float deltaTime)
{
	m_actor->m_knockBack.update(deltaTime);

	if (m_actor->m_knockBack.isEnd())
		m_gravity -= 0.007f;
	m_actor->changeGravity(m_gravity);

	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->changeGravity(-0.05f);
		m_actor->changeState(ACTOR_STATE::ESTAND);
	}
	if (m_actor->m_status.getHp() <= 0)
	{
		m_actor->changeGravity(-0.05f);
		changeState(ACTOR_STATE::EDEAD);
		m_actor->m_collision.clear();
	}
}

Enemy::EDamageState * Enemy::EDamageState::clone() const
{
	return new EDamageState(*this);
}