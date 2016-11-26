#include"../../../header/state/player/LandingRigidityState.h"
#include "../../../header/data/ANIMATION_ID.h"
Player::LandingRigidityState::LandingRigidityState(Player* _player)
	:ActorState(_player)
{
}

void Player::LandingRigidityState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), false);
}
void Player::LandingRigidityState::action(float deltaTime)
{
	m_actor->control();
	changeState(ACTOR_STATE::STAND);
}
Player::LandingRigidityState* Player::LandingRigidityState::clone() const
{
	return new LandingRigidityState(*this);
}