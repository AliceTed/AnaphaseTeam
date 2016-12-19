/**
@file	SplineManager.h
@brief	ƒXƒvƒ‰ƒCƒ“ŠÇ—Ò
@author Yuuho Aritomi
@date	2016/12/19
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "SPLINE_ANIMATION_ID.h"

class AnimationSplineData;

class SplineAnimManager
{
public:
	SplineAnimManager(void);

	~SplineAnimManager();

	void load(void);

	void changeID(SPLINE_ANIMATION_ID _id);

	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

private:
	SPLINE_ANIMATION_ID m_currentID;

	std::unique_ptr<AnimationSplineData> m_datas;
};