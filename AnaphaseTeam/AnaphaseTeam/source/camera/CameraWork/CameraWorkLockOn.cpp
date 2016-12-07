#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/math/AMath.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera, GSvector2* _rotate) :
	CameraWork(_camera),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkLockOn.cw")),
	m_rotate(_rotate),
	m_elevation(0.0f),
	m_distance(0.0f),
	m_distance_lockOn(0.0f),
	m_followSpeed_position(0.0f),
	m_followSpeed_target(0.0f),
	m_offset(0.0f)
{
	m_elevation = m_parameter->get(0);
	m_distance = m_parameter->get(1);
	m_distance_lockOn = m_parameter->get(2);
	m_followSpeed_position = m_parameter->get(3);
	m_followSpeed_target = m_parameter->get(4);
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}


void CameraWorkLockOn::draw_cameraWork(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& enemy = m_camera->cameraTarget_enemy();

	const GSvector2 p1 = GSvector2(player.x, player.z);
	const GSvector2 p2 = GSvector2(m_camera->position().x, m_camera->position().z);
	const GSvector2 p3 = GSvector2(enemy.x, enemy.z);

	const int n = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);

	float f = 30;

	if (n > 0)
	{
		m_offset = f;
	}

	if (n < 0)
	{
		m_offset = -f;
	}

	GSvector3 vector = enemy - player;

	GSvector3 center = centerPoint(player, enemy);

	float distance_p_e = gsVector3Distance(&player, &enemy);
	float distance_p_c = gsVector3Distance(&player, &center);

	update_toEleDir(vector, distance_p_c);

	m_camera->cameraWork_dolly(
		(center + m_offset_target),
		*m_rotate,
		distance_p_c + m_distance,
		m_followSpeed_position,
		m_followSpeed_target
	);

	return;
}


const GSvector3 CameraWorkLockOn::centerPoint(const GSvector3& _p1, const GSvector3& _p2)
{
	return (_p1 + _p2) / 2;
}


void CameraWorkLockOn::update_toEleDir(const GSvector3& _vec, float _distance)
{
	if (_distance > 0.5f)
	{
		gsVector3ToEleDir(&m_rotate->x, &m_rotate->y, &_vec);

		m_rotate->x = m_elevation;
		m_rotate->y += 180 + m_offset;
	}
}