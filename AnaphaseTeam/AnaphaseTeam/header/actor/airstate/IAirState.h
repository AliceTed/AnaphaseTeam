#pragma once
class jumpontrol;
__interface IAirState
{
public:
	void airAction(jumpControl* _jumpAction, float deltatime) = 0;
};