#include "../../../header/actor/airstate/RigorState.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/actionstate/StandState.h"

RigorState::RigorState()
	:m_RigorTimer(30)
{
}
RigorState::~RigorState()
{
}
void RigorState::start(jumpControl * _jumpAction)
{
	m_RigorTimer.initialize();
}
void RigorState::airAction(jumpControl * _jumpAction, Player * _player, float deltaTime)
{
	_player->jumpRigor();
	m_RigorTimer.update(deltaTime);
	if (m_RigorTimer.isEnd())
	{
		_player->actionChange(std::make_shared<StandState>());
	}
}
void RigorState::next(jumpControl * _control)
{
}