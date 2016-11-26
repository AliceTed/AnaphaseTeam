#include "../../../header/state/player/StandState.h"

#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
Player::StandState::StandState(Player* _player)
	:ActorState(_player)
{
}

void Player::StandState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true, true, true, 2.0f);
}
void Player::StandState::action(float deltaTime)
{
	if (!m_actor->m_isGround)
	{
		changeState(ACTOR_STATE::LIMITFALL);
		return;
	}
	if (m_actor->m_device->input()->move())
	{
		changeState(ACTOR_STATE::RUN);
		return;
	}
	m_actor->subActionStart();	
	m_actor->control();
}
Player::StandState* Player::StandState::clone() const
{
	return new StandState(*this);
}