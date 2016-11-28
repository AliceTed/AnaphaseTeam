#include "../../header/airstate/PreparationState.h"
#include "../../header/airstate/FirstStep.h"
#include "../../header/subaction/JumpControl.h"
#include "../../header/actor/Player/Player.h"

PreparationState::PreparationState(JumpControl* _control, Player* _player)
	:m_isEnd(false),
	m_control(_control),
	m_player(_player)
{
}

PreparationState::~PreparationState()
{
}

void PreparationState::start()
{
	m_isEnd = false;
}
/**
* @fn
* @brief FirstStep�Ɉڍs
*/
void PreparationState::update(float deltaTime)
{
	m_isEnd = true;
	m_next = std::make_shared<FirstStep>(m_control, m_player);
}

const bool PreparationState::isEnd() const
{
	return m_isEnd;
}

std::shared_ptr<IAirState> PreparationState::next() const
{
	return m_next;
}
