#pragma once

#include <gslib.h>
class SplineVec3;

class AnimationSpline
{
public:
	AnimationSpline(SplineVec3* _sVec3);

	~AnimationSpline();

	void resetTime(void);

	GSvector3 run(float _speed);

private:
	SplineVec3* m_sVec3;

	float m_timer;
};