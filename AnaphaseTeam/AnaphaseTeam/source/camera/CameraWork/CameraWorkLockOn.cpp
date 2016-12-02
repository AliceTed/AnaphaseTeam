#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/ACalc.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera, GSvector2* _rotate) :
	CameraWork(_camera),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkLockOn.cw")),
	m_rotate(_rotate),
	m_elevation(0.0f),
	m_distance(0.0f),
	m_followSpeed_position(0.0f),
	m_followSpeed_target(0.0f)
{
	m_elevation = m_parameter->get(0);
	m_distance = m_parameter->get(1);
	m_followSpeed_position = m_parameter->get(2);
	m_followSpeed_target = m_parameter->get(2);
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}



void CameraWorkLockOn::draw_cameraWork(void)
{
	m_camera->zoom(90.0f);

	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& enemy = m_camera->cameraTarget_enemy();
	GSvector3 vector = enemy - player;
	GSvector3 center = (player + enemy) / 2;
	float distance_p_e = gsVector3Distance(&player, &enemy);
	float distance_p_c = gsVector3Distance(&player, &center);

	if (distance_p_c > m_distance)
	{
		gsVector3ToEleDir(&m_rotate->x, &m_rotate->y, &vector);

		m_rotate->x = m_elevation;
		m_rotate->y += 180;
	}

	m_camera->cameraWork_dolly(
		(center + GSvector3(0, 1, 0)),
		*m_rotate,
		distance_p_c + m_distance,
		m_followSpeed_position,
		m_followSpeed_target
	);

	return;
}