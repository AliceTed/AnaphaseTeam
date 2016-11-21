#pragma once

#include "../../CameraActionDolly.h"

class CameraActionDollyStage1_3 : public CameraActionDolly
{
public:
	CameraActionDollyStage1_3(
		Camera*		_camera, 
		GSvector3*	_target,
		float*		_elevation,
		float*		_direction);

	~CameraActionDollyStage1_3() override;
};