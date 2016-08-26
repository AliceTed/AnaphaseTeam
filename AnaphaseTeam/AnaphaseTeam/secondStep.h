#pragma once
#include "header\actor\airstate\IAirState.h"
#include "header\actor\airstate\jumpControl.h"

class secondStep:public IAirState
{
public:
	secondStep();
	~secondStep();
	void airAction(jumpControl* _jumpAction);
private:
	static const float SecondStepPow;
};