#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class firstStep:public IAirState
{
public:
	firstStep();
	~firstStep();
	void airAction(jumpControl* _jumpAction);
private:
	static const float FirstStepPow;
};