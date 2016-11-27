#include "../../../header/state/player/AttackState.h"
#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
Player::AttackState::AttackState(Player* _player)
	:ActorState(_player)
{
}

void Player::AttackState::start()
{
}
void Player::AttackState::action(float deltaTime)
{
	m_actor->m_combo.update(deltaTime);
	input();
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->m_combo.change();
	}
	gsVector3Lerp(&m_actor->m_transform.m_translate, &m_actor->m_transform.m_translate, &m_actor->target, deltaTime * 0.1f);
	if (m_actor->m_combo.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::AttackState* Player::AttackState::clone() const
{
	return new AttackState(*this);
}

void Player::AttackState::input()
{
	Input_Ptr& input = m_actor->m_device->input();
	if (input->quickAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_actor->m_combo.next(false);
	}
	if (input->slowAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_actor->m_combo.next(true);
	}
}
