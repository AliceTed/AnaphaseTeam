#include "../../../header/camera/CameraWork/_CameraWork.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWork::CameraWork(Camera* _camera) : 
	m_camera(_camera),
	m_paramater_def(std::make_unique<CWParameterReader>("./res/data/CameraWorkDef.cw")),
	m_offset_target(0.0f, 0.0f, 0.0f)
{
	//�J�����̃^�[�Q�b�g�̃I�t�Z�b�g��ݒ�
	m_offset_target = GSvector3(
		(*m_paramater_def)[0],
		(*m_paramater_def)[1],
		(*m_paramater_def)[2]
	);
}

CameraWork::~CameraWork()
{

}

void CameraWork::start(void)
{
}

void CameraWork::run(float _deltaTime)
{
	//�Ƃ肠�����J�����̈ʒu�ƃ^�[�Q�b�g��K���ɐݒ�
	m_camera->tracking_position(GSvector3(0.0f, 0.0f, 0.0f));
	m_camera->tracking_lookAt(GSvector3(0.0f, 0.0f, -1.0f));;

	return;
}