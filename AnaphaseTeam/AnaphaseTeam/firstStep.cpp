#include "header\actor\airstate\firstStep.h"

const float firstStep::FirstStepPow = 1.2f;
firstStep::firstStep()
{

}

firstStep::~firstStep()
{

}

void firstStep::airAction(jumpControl* _jumpAction)
{
	_jumpAction->start(FirstStepPow);
}