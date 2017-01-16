#include "state/player/HomingStartState.h"
#include "device/GameDevice.h"

Player::HomingStartState::HomingStartState(Player* _player)
	:ActorState(_player)
{
}

void Player::HomingStartState::start()
{
	m_actor->m_animatorOne.changeAnimation(ANIMATION_ID::DELAY);
}
void Player::HomingStartState::action(float deltaTime)
{
	Sleep(20);
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		changeState(ACTOR_STATE::HOMING);
	}
}
Player::HomingStartState* Player::HomingStartState::clone() const
{
	return new HomingStartState(*this);
}
