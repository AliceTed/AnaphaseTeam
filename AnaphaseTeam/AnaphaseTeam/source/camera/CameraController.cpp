/**
@file CameraController
@brief ƒJƒƒ‰‚ğ‘€ì‚·‚é
@author Yuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/ACalc.h"
#include <string>

CameraController::CameraController(Camera* _camera) :
	m_camera(_camera),
	m_distance(1),
	m_pitch(0),
	m_yow(0)
{

}

CameraController::CameraController(Camera* _camera, const float _distance, const float _pitch, const float _yow) :
	m_camera(_camera),
	m_distance(_distance),
	m_pitch(_pitch),
	m_yow(_yow)
{
	ACalc::to_rad(&m_pitch);
	ACalc::to_rad(&m_yow);
}

void CameraController::change_control(Camera* _camera)
{
	m_camera = _camera;

	return;
}

void CameraController::follow(const GSvector3* _target, const float _speed)
{
	GSvector3 target;

	target = m_camera->POSITION();

	ACalc::tracking(&target, _target, _speed);

	m_camera->move(&target);

	return;
}

void CameraController::special_move1(GSvector3* _target1, GSvector3* _target2, float _pitch, float _distance)
{
	float ele, dir, distance, pitch, yow;
	GSvector3 vector, target;

	m_camera->look_at(_target2);

	distance = gsVector3Distance(_target1, _target2);

	ACalc::vector(&vector, _target1, _target2);

	gsVector3ToEleDir(&ele, &dir, &vector);

	//pitch = ele;
	pitch = ele+10.0f;
	yow = dir + 180;

	ACalc::to_rad(&pitch);
	ACalc::to_rad(&yow);

	ACalc::clamp(&pitch, 0, 360);
	
	//‹——£§ŒÀ
	ACalc::clamp(&distance,10, 50);

	ACalc::rotate(&target, _target2, pitch, yow, distance * _distance);

	follow(&target, 0.09f);

	m_camera->update();

	return;
}

const float CameraController::DIRECTION(void) const
{
	float ele, dir;
	GSvector3 vector;

	ACalc::vector(&vector, &m_camera->POSITION(), &m_camera->TARGET());

	gsVector3ToEleDir(&ele, &dir, &vector);

	return dir;
}
