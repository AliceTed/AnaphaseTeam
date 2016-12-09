#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/Camera.h"

CameraWorkDead::CameraWorkDead(Camera* _camera) :
	CameraWork(_camera)
{
}



CameraWorkDead::~CameraWorkDead()
{

}

void CameraWorkDead::start(void)
{
	//�J�����̃Y�[���͈͂�ݒ�
	m_camera->zoom_clamp(20, 180);
}

//������
void CameraWorkDead::run(float _deltaTime)
{
	//�ϐ��̖��O�������̂ŒZ�����O�ɕύX
	const GSvector3& player = m_camera->cameraTarget_player();

	//�����_���v���C���[�ɌŒ�
	m_camera->tracking_lookAt(player + m_offset_target, 0.5f);

	//�J�������Y�[���A�b�v����
	m_camera->zoom_in(1.0f);

	return;
}