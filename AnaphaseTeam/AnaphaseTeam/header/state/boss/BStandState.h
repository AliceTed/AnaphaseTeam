#pragma once
#include "actor\Boss\Boss.h"
#include"state\ActorState.h"

class Boss::BStandState :public ActorState<Boss>
{
public:
	Boss::BStandState(Boss* _actor);
	void start()override;
	void action(float deltatime)override;
	BStandState* clone()const override;
private:
};