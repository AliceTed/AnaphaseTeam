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
	//m_parameter(std::make_unique<CWParameterReader>("./res/document/CameraWorkNormal.csv")),
	m_speed_input(3.0f),
	m_distance(5.0f),
	m_followSpeed_position(0.5f),
	m_followSpeed_target(0.5f)
{
	//m_speed_input = m_parameter->get(0);
	//m_distance = m_parameter->get(1);
	//m_followSpeed_position = m_parameter->get(2);
	//m_followSpeed_target = m_parameter->get(3);
}



CameraWorkNormal::~CameraWorkNormal()
{
}



void CameraWorkNormal::update(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();

	m_rotate->x -= velocity().y * m_speed_input;
	m_rotate->y += velocity().x * m_speed_input;

	m_camera->cameraWork_dolly(
		player,
		(*m_rotate),
		m_distance,
		m_followSpeed_position,
		m_followSpeed_target
	);

	return;
}


const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;

	gsXBoxPadGetRightAxis(0, &velocity);

	return velocity;
}