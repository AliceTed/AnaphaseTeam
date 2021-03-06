#include"state/player/MoveState.h"
#include "data/id/ANIMATION_ID.h"
#include "device/GameDevice.h"
const float Player::MoveState::SPEED = 0.1f;
Player::MoveState::MoveState(Player* _player)
	:ActorState(_player)
{
}

void Player::MoveState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::RUN), true, true, true);
}
void Player::MoveState::action(float deltaTime)
{
	m_actor->movement(deltaTime,SPEED);
	m_actor->subActionStart();
	m_actor->control();
	if (!GameDevice::getInstacnce().input()->move())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::MoveState* Player::MoveState::clone() const
{
	return new MoveState(*this);
}