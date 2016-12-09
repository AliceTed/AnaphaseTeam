#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWorkNormal::CameraWorkNormal(Camera* _camera, GSvector2* _rotate) :
	CameraWork(_camera),
	m_rotate(_rotate),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkNormal.cw")),
	m_speed_input(0.0f),
	m_distance(0.0f),
	m_trackingSpeed(0.0f, 0.0f)
{
	//�ǂݍ��񂾃p�����[�^���e�ϐ��ɑ��
	m_speed_input			= (*m_parameter)[0];
	m_distance				= (*m_parameter)[1];
	m_trackingSpeed = {
		(*m_parameter)[2],
		(*m_parameter)[3]
	};
}



CameraWorkNormal::~CameraWorkNormal()
{
}



void CameraWorkNormal::draw_cameraWork(void)
{
	//���������߂�ǂ������̂Ő錾
	const GSvector3& player = m_camera->cameraTarget_player();

	//��]�����X�V
	m_rotate->x -= velocity().y * m_speed_input;	//�t�ɓ����������̂ň����Ƃ�
	m_rotate->y += velocity().x * m_speed_input;

	//�J�������[�N�E�h���[�̏���
	m_camera->cameraWork_dolly(
		(player + m_offset_target),
		(*m_rotate),
		m_distance,
		m_trackingSpeed
	);

	return;
}


const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;

	//�E�X�e�B�b�N�̓|�ꂽ�������擾����
	gsXBoxPadGetRightAxis(0, &velocity);

	return velocity;
}