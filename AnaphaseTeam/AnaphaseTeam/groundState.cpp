#include "groundState.h"

groundState::groundState()
{

}

groundState::~groundState()
{

}

void groundState::airAction(jumpControl* _jumpAction)
{
	_jumpAction->groundHit();
}