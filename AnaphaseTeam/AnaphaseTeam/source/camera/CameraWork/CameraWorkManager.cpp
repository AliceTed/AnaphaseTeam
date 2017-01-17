#include "camera/CameraWork/CameraWorkManager.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CameraWorkEmpty.h"
#include "camera/CameraWork/CameraWorkTest.h"
#include "camera/CameraWork/CameraWorkNormal.h"
#include "camera/CameraWork/CameraWorkLockOn.h"
#include "camera/CameraWork/CameraWorkDead.h"
#include "camera/CameraWork/CameraWorkData.h"
#include "camera/CameraWork/CameraWorkNormalBattle.h"
#include "camera/CameraWork/CameraWorkEvent.h"
#include "camera/CameraWork/I_CameraWork.h"
#include "spline/SplineAnimManager.h"

CameraWorkManager::CameraWorkManager(Camera* _camera, bool* _isLockOn) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_splineAnimManager(std::make_shared<SplineAnimManager>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraWork("none"),
	m_isLockOn(_isLockOn)
{

}

CameraWorkManager::~CameraWorkManager()
{

}

void CameraWorkManager::load(void)
{
	//�X�v���C���Ȑ��A�j���[�V����
	m_splineAnimManager->load();

	//�e�J�����̒ǉ�
	m_cameraData->add(								//�������Ȃ�
		"none",
		new CameraWorkEmpty(m_camera)
	);
	m_cameraData->add(								//�e�X�g
		"test",
		new CameraWorkTest(m_camera)
	);
	m_cameraData->add(								//�ʏ�J����
		"normal",
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(								//���b�N�I���J����
		"lockon",
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(
		"normal_battle",
		new CameraWorkNormalBattle(m_camera, m_isLockOn)
	);
	m_cameraData->add(								//���S�J����
		"dead",
		new CameraWorkDead(m_camera)
	);
	m_cameraData->add(
		"event",
		new CameraWorkEvent(m_camera, m_splineAnimManager.get())
	);
}

void CameraWorkManager::change_cameraWork(std::string _id)
{
	//���݂̃J�������[�N�̍X�V
	m_current_cameraWork = _id;

	//���݂̃J�����̏�����
	m_cameraData->get(m_current_cameraWork)->start();
}

void CameraWorkManager::run(float _deltaTime)
{
	if (m_cameraData->get(m_current_cameraWork)->isEnd())
	{
		change_cameraWork(m_cameraData->get(m_current_cameraWork)->nextCameraWork());
	}

	//���݂̃J�������[�N�̎��s
	m_cameraData->get(m_current_cameraWork)->run(_deltaTime);

	return;
}