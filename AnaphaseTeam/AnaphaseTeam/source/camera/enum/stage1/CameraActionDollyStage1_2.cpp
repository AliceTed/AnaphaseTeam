#include "../../../../header/camera/enum/stage1/CameraActionDollyStage1_2.h"
#include "../../../../header/camera/CameraActionDolly.h"
#include "../../../../header/camera/Camera.h"

CameraActionDollyStage1_2::CameraActionDollyStage1_2(
	Camera*		_camera,
	GSvector3*	_cameraTarget,
	float*		_elevation,
	float*		_direction) :
	CameraActionDolly(_camera, _cameraTarget, _elevation, _direction)
{
	initialize(8);
}

CameraActionDollyStage1_2::~CameraActionDollyStage1_2()
{

}