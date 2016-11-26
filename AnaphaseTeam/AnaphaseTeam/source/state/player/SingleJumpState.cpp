#include"../../../header/state/player/SingleJumpState.h"
#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
Player::SingleJumpState::SingleJumpState(Player* _player)
	:ActorState(_player),
	m_jumping(_player)
{
}

void Player::SingleJumpState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), false);
	m_jumping.start(0.5f);
}
void Player::SingleJumpState::action(float deltaTime)
{
	float speed=0.05f;
	m_actor->movement(deltaTime,speed);
	m_actor->control();
	m_jumping.update(deltaTime);
	if (m_actor->m_isGround)
	{
		changeState(ACTOR_STATE::LANDINGRIGIDITY);
		return;
	}
	if (m_actor->m_device->input()->jump())
	{
		changeState(ACTOR_STATE::DOUBLEJUMP);
	}
}
Player::SingleJumpState* Player::SingleJumpState::clone() const
{
	return new SingleJumpState(*this);
}