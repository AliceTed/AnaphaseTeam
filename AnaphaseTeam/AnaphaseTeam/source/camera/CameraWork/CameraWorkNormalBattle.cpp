#include "camera/CameraWork/CameraWorkNormalBattle.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CameraWorkNormal.h"
#include "camera/CameraWork/CameraWorkLockOn.h"

CameraWorkNormalBattle::CameraWorkNormalBattle(Camera * _camera, bool * _isLockOn) :
CameraWorkEmpty(_camera),
m_rotate(0.0f, 270.0f),
m_normal(std::make_unique<CameraWorkNormal>(_camera, &m_rotate)),
m_lockon(std::make_unique<CameraWorkLockOn>(_camera, &m_rotate)),
m_isLockOn(_isLockOn)
{
}

CameraWorkNormalBattle::~CameraWorkNormalBattle()
{

}

void CameraWorkNormalBattle::start(void)
{
	m_normal->start();
	m_lockon->start();

	m_nextCameraWork = "dead";
	m_isEnd = false;
}

void CameraWorkNormalBattle::run(float _deltaTime)
{
	if (*m_isLockOn)
	{
		m_lockon->run(_deltaTime);
	}
	else
	{
		m_normal->run(_deltaTime);
	}

	return;
}

std::string CameraWorkNormalBattle::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkNormalBattle::isEnd(void)
{
	return m_isEnd;
}
