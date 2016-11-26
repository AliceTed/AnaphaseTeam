#include"../../../header/state/player/StepState.h"
#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
Player::StepState::StepState(Player* _player)
	:ActorState(_player)
{
}

void Player::StepState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true);
}
void Player::StepState::action(float deltaTime)
{
	m_actor->m_avoid.update(deltaTime);
	if (m_actor->m_avoid.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::StepState* Player::StepState::clone() const
{
	return new StepState(*this);
}