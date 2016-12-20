#include "../../../header/camera/CameraWork/CameraWorkManager.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CameraWorkEmpty.h"
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/CameraWorkNormalBattle.h"
#include "../../../header/camera/CameraWork/CameraWorkEvent.h"
#include "../../../header/camera/CameraWork/I_CameraWork.h"
#include "../../../header/spline/SplineAnimManager.h"

CameraWorkManager::CameraWorkManager(Camera* _camera, bool* _isLockOn) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_splineAnimManager(std::make_shared<SplineAnimManager>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraWork(E_CameraWorkID::NONE),
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
		E_CameraWorkID::NONE,
		new CameraWorkEmpty(m_camera)
	);
	m_cameraData->add(								//�e�X�g
		E_CameraWorkID::TEST,
		new CameraWorkTest(m_camera)
	);
	m_cameraData->add(								//�ʏ�J����
		E_CameraWorkID::NORMAL,
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(								//���b�N�I���J����
		E_CameraWorkID::LOCK_ON,
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(
		E_CameraWorkID::NORMAL_BATTLE,
		new CameraWorkNormalBattle(m_camera, m_isLockOn)
	);
	m_cameraData->add(								//���S�J����
		E_CameraWorkID::DEAD,
		new CameraWorkDead(m_camera)
	);
	m_cameraData->add(
		E_CameraWorkID::EVENT,
		new CameraWorkEvent(m_camera, m_splineAnimManager.get())
	);
}

void CameraWorkManager::change_cameraWork(const E_CameraWorkID _id)
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