#include "camera/CameraWork/CameraWorkEmpty.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CWParameterReader.h"

CameraWorkEmpty::CameraWorkEmpty(Camera* _camera) :
	m_camera(_camera),
	m_paramater_def(std::make_unique<CWParameterReader>("./res/data/CameraWorkDef.cw")),
	m_offset_target(0.0f, 0.0f, 0.0f),
	m_nextCameraWork("none"),
	m_isEnd(false)
{
	//カメラのターゲットのオフセットを設定
	m_offset_target = GSvector3(
		(*m_paramater_def)[0],
		(*m_paramater_def)[1],
		(*m_paramater_def)[2]
	);
}

CameraWorkEmpty::~CameraWorkEmpty()
{

}

void CameraWorkEmpty::start(void)
{
	m_isEnd = false;
}

void CameraWorkEmpty::run(float _deltaTime)
{
	//とりあえずカメラの位置とターゲットを適当に設定
	m_camera->tracking_position(GSvector3(0.0f, 0.0f, 0.0f));
	m_camera->tracking_lookAt(GSvector3(0.0f, 0.0f, -1.0f));;

	return;
}

std::string CameraWorkEmpty::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkEmpty::isEnd(void)
{
	return m_isEnd;
}