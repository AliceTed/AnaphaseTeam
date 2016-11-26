#include"../../../header/state/player/AirState.h"
#include "../../../header/data/ANIMATION_ID.h"
Player::AirState::AirState(Player* _player)
	:ActorState(_player)
{
}

void Player::AirState::start()
{
}
void Player::AirState::action(float deltaTime)
{
	m_actor->m_SubAction.update(deltaTime, SubActionType::JUMP);
	if (m_actor->m_SubAction.isEnd(SubActionType::JUMP))
	{
		m_actor->m_isJumpAttack = false;
		changeState(ACTOR_STATE::STAND);
	}
}
Player::AirState* Player::AirState::clone() const
{
	return new AirState(*this);
}