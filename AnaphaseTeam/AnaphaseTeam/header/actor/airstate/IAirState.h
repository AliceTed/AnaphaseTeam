#pragma once
class jumpControl;
__interface IAirState
{
public:
	void airAction(jumpControl* _jumpAction) = 0;
};