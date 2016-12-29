#include "../../../header/state/player/HomingStartState.h"

Player::HomingStartState::HomingStartState(Player* _player)
	:ActorState(_player)
{
}

void Player::HomingStartState::start()
{
	m_actor->m_animatorOne.changeAnimation(ANIMATION_ID::ATTACK5);
}
void Player::HomingStartState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		changeState(ACTOR_STATE::HOMING);
	}
}
Player::HomingStartState* Player::HomingStartState::clone() const
{
	return new HomingStartState(*this);
}
