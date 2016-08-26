#pragma once
#include "header\actor\airstate\IAirState.h"
#include "header\actor\airstate\jumpControl.h"
class groundState:public IAirState
{
public:
	groundState();
	~groundState();
	void airAction(jumpControl* _jumpAction);
};