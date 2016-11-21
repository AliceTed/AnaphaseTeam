#include "../../header/camera/CameraActionDolly.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/ACalc.h"
#include "../../header/math/Calculate.h"

CameraActionDolly::CameraActionDolly(
	Camera*			_camera,
	GSvector3*		_target,
	float*			_elevation,
	float*			_direction
) :
	m_camera		(_camera),
	m_target		(_target),
	m_elevation		(_elevation),
	m_direction		(_direction),
	m_distance		(0.0f)
{

}



CameraActionDolly::~CameraActionDolly()
{

}



void CameraActionDolly::initialize(const float _distance)
{
	m_distance =	_distance;
}



void CameraActionDolly::run(void)
{
	ACalc		calc;
	Math::Clamp clamp;
	Math::Wrap	wrap;
	float		elevation, direction;
	GSvector3	vector;

	//仰角と方位角をコピーする
	elevation = *m_elevation;
	direction = *m_direction;

	//カメラの回転位置を求める
	calc.rotate(&vector, *m_target, elevation, direction, m_distance);

	//カメラをターゲットに追尾させる
	m_camera->follow_position(vector, 0.5f);

	//カメラの注視点を更新する
	m_camera->lookAt(*m_target);

	return;
}