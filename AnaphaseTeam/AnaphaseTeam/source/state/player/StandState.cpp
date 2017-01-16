#include "state/player/StandState.h"

#include "data/id/ANIMATION_ID.h"
#include "device/GameDevice.h"
Player::StandState::StandState(Player* _player)
	:ActorState(_player)
{
}

void Player::StandState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND),true, true, true);
}
void Player::StandState::action(float deltaTime)
{
	//lerp中にアニメーションが切り替わらないので
	//m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true, true, true);
	m_actor->control();
	if (!m_actor->m_isGround)
	{
		return;
	}
	if (GameDevice::getInstacnce().input()->move())
	{
		changeState(ACTOR_STATE::RUN);
		return;
	}
	m_actor->subActionStart();	
	
}
Player::StandState* Player::StandState::clone() const
{
	return new StandState(*this);
}