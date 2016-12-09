#include "../../../header/camera/CameraWork/CameraWorkManager.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/I_CameraWork.h"

CameraWorkManager::CameraWorkManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraWork(E_CameraWorkID::NONE)
{

}

CameraWorkManager::~CameraWorkManager()
{

}

void CameraWorkManager::load(void)
{
	//�e�J�����̒ǉ�
	m_cameraData->add(								//�ʏ�J����
		E_CameraWorkID::NORMAL,
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(								//���b�N�I���J����
		E_CameraWorkID::LOCK_ON,
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(								//���S�J����
		E_CameraWorkID::DEAD,
		new CameraWorkDead(m_camera)
	);
}

void CameraWorkManager::change_cameraWork(const E_CameraWorkID _id)
{
	//���݂̃J�������[�N�̍X�V
	m_current_cameraWork = _id;
}

void CameraWorkManager::update(float _deltaTime)
{
	//�J�������[�N�������Ȃ��Ȃ牽�����Ȃ�
	if (m_current_cameraWork == E_CameraWorkID::NONE)
	{
		return;
	}

	//���݂̃J�������[�N�̍X�V
	m_cameraData->get(m_current_cameraWork)->update(_deltaTime);

	return;
}

void CameraWorkManager::draw(void)
{
	//�J�������[�N�������Ȃ��Ȃ牽�����Ȃ�
	if (m_current_cameraWork == E_CameraWorkID::NONE)
	{
		return;
	}

	//���݂̃J�������[�N�̕`��
	m_cameraData->get(m_current_cameraWork)->draw();

	//�J�������[�N�̍X�V
	m_camera->update();

	return;
}