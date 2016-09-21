#include "../../header/airstate/RigorState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/actionstate/StandState.h"
#include "../../header/airstate/GroundState.h"

RigorState::RigorState()
	:m_RigorTimer(20)
{
}
RigorState::~RigorState()
{
}
void RigorState::start(JumpControl * _control)
{
	m_RigorTimer.initialize();
}
void RigorState::airAction(JumpControl * _control, Player * _player, float deltaTime)
{
	_player->jumpRigor();
	m_RigorTimer.update(deltaTime);
	if (m_RigorTimer.isEnd())
	{
		_control->airActionChange(std::make_shared<GroundState>());
		_player->actionChange(std::make_shared<StandState>());
	}
}
void RigorState::next(JumpControl * _control)
{

}