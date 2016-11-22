
#include "../../../../header/camera/enum/stage1/CameraActionDollyStage1_1.h"
#include "../../../../header/camera/Camera.h"

CameraActionDollyStage1_1::CameraActionDollyStage1_1(
	Camera*		_camera,
	GSvector3*	_target,
	float*		_elevation,
	float*		_direction
) :
	CameraActionDolly(_camera, _target, _elevation, _direction)
{
	initialize(3);
}



CameraActionDollyStage1_1::~CameraActionDollyStage1_1()
{

}