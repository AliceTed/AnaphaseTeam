#include"state/player/DoubleJumpState.h"
#include "data/id/ANIMATION_ID.h"
Player::DoubleJumpState::DoubleJumpState(Player* _player)
	:ActorState(_player),
	m_jumping(_player)
{
}

void Player::DoubleJumpState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), false);
	m_jumping.start(0.45f);
}
void Player::DoubleJumpState::action(float deltaTime)
{
	float speed = 0.05f;
	m_actor->movement(deltaTime, speed);
	m_actor->control();
	m_jumping.update(deltaTime);
	if (m_actor->m_isGround)
	{
		changeState(ACTOR_STATE::LANDINGRIGIDITY);
	}
}
Player::DoubleJumpState* Player::DoubleJumpState::clone() const
{
	return new DoubleJumpState(*this);
}