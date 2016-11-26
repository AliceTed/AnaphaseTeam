#include "../../../header/state/player/AttackState.h"
#include "../../../header/data/ANIMATION_ID.h"
Player::AttackState::AttackState(Player* _player)
	:ActorState(_player)
{
}

void Player::AttackState::start()
{
}
void Player::AttackState::action(float deltaTime)
{
	m_actor->m_SubAction.jumpPowerOff();	
	m_actor->m_attackManager.update(deltaTime, m_actor);
	gsVector3Lerp(&m_actor->m_transform.m_translate, &m_actor->m_transform.m_translate, &m_actor->target, deltaTime * 0.1f);
	if (m_actor->m_attackManager.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::AttackState* Player::AttackState::clone() const
{
	return new AttackState(*this);
}