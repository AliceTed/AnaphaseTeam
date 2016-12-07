#include"../../../header/state/player/StepState.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"
Player::StepState::StepState(Player* _player)
	:ActorState(_player),
	m_step(_player)
{
}

void Player::StepState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true);
	//¡‚Í³–ÊŒÅ’è
	//‚±‚ê is ‚È‚É
	//ƒNƒ\
	if (m_actor->m_isLockOn)
	{
		//m_step.start(m_actor->m_lockon.);
		m_actor->test();
	}
	m_step.start(m_actor->m_transform.front());
}
void Player::StepState::action(float deltaTime)
{
	m_step.update(deltaTime);
	if (m_step.isEnd())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::StepState* Player::StepState::clone() const
{
	return new StepState(*this);
}