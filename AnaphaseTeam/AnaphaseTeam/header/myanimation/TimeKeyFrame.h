#pragma once
#include "../transform/Transform.h"
struct TimeKeyFrame
{
	TimeKeyFrame();
	TimeKeyFrame(const Transform& _target,float _time);
	
	Transform target;
	float time;
};