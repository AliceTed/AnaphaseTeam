#include "groundState.h"

groundState::groundState()
{

}

groundState::~groundState()
{

}

void groundState::airAction(jumpControl* _jumpAction, float deltatime)
{
	_jumpAction->groundHit();
}