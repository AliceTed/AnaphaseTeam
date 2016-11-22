#include "../../../../header/camera/enum/stage1/CameraActionDollyStage1_3.h"
#include "../../../../header/camera/CameraActionDolly.h"
#include "../../../../header/camera/Camera.h"

CameraActionDollyStage1_3::CameraActionDollyStage1_3(
	Camera*		_camera,
	GSvector3*	_target,
	float*		_elevation,
	float*		_direction
) :
	CameraActionDolly(_camera, _target, _elevation, _direction)
{
	initialize(13.0f);
}

CameraActionDollyStage1_3::~CameraActionDollyStage1_3()
{

}