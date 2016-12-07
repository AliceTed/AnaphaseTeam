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
	m_offset_value(0.0f),
	m_offset(0.0f)
{
	m_elevation = m_parameter->get(0);
	m_distance = m_parameter->get(1);
	m_distance_lockOn = m_parameter->get(2);
	m_followSpeed_position = m_parameter->get(3);
	m_followSpeed_target = m_parameter->get(4);
	m_offset_value = m_parameter->get(5);
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}


void CameraWorkLockOn::draw_cameraWork(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& target = m_camera->cameraTarget_enemy();

	whichSide(player, target);

	GSvector3 vector = AMath::vec3_vector(player, target);

	GSvector3 center = AMath::vec3_center(player, target);

	float distance_p_e = gsVector3Distance(&player, &target);
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


void CameraWorkLockOn::update_toEleDir(const GSvector3& _vec, float _distance)
{
	if (_distance > m_distance_lockOn)
	{
		gsVector3ToEleDir(&m_rotate->x, &m_rotate->y, &_vec);

		m_rotate->x = m_elevation;
		m_rotate->y += 180 + m_offset;
	}
}

void CameraWorkLockOn::whichSide(const GSvector3 & _player, const GSvector3 & _target)
{
	const GSvector2 p1 = GSvector2(_player.x, _player.z);
	const GSvector2 p2 = GSvector2(m_camera->position().x, m_camera->position().z);
	const GSvector2 p3 = GSvector2(_target.x, _target.z);

	int n = AMath::side(p1, p2, p3);

	float f = 30;

	if (n > 0)
	{
		m_offset = m_offset_value;
	}

	if (n < 0)
	{
		m_offset = -m_offset_value;
	}
}
