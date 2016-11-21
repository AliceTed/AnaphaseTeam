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

	//�p�ƕ��ʊp���R�s�[����
	elevation = *m_elevation;
	direction = *m_direction;

	//�J�����̉�]�ʒu�����߂�
	calc.rotate(&vector, *m_target, elevation, direction, m_distance);

	//�J�������^�[�Q�b�g�ɒǔ�������
	m_camera->follow_position(vector, 0.5f);

	//�J�����̒����_���X�V����
	m_camera->lookAt(*m_target);

	return;
}