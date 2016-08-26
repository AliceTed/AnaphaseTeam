#include "secondStep.h"
const float secondStep::SecondStepPow = 1.0f;
secondStep::secondStep()
{

}

secondStep::~secondStep()
{

}

void secondStep::airAction(jumpControl* _jumpAction)
{
	_jumpAction->start(SecondStepPow);
}