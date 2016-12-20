#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/math/AMath.h"

CameraWorkNormal::CameraWorkNormal(Camera* _camera, GSvector2* _rotate) :
	CameraWorkEmpty(_camera),
	m_rotate(_rotate),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkNormal.cw")),
	m_speed_input(0.0f),
	m_distance(0.0f),
	m_trackingSpeed(0.0f, 0.0f),
	m_clamp_elevation(70.0f)
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

void CameraWorkNormal::start(void)
{
	m_camera->initialize_zoom();
	
	m_nextCameraWork = E_CameraWorkID::NONE;
	m_isEnd = false;
}

void CameraWorkNormal::run(float _deltaTime)
{
	Math::Clamp clamp;
	//���������߂�ǂ������̂Ő錾
	const GSvector3& player = m_camera->get_cameraTarget_player();

	//�{�^���������ꂽ�Ƃ��J���������ɉ񂷏���
	resetCamera();

	//��]�����X�V
	m_rotate->x -= velocity().y * m_speed_input;	//�t�ɓ����������̂ň����Ƃ�
	m_rotate->y += velocity().x * m_speed_input;

	//�����̉�]�𐧌�
	m_rotate->x = clamp(m_rotate->x, -m_clamp_elevation, m_clamp_elevation);

	//�J�������[�N�E�h���[�̏���
	m_camera->cameraWork_dolly(
		(player + m_offset_target),
		(*m_rotate),
		m_distance,
		m_trackingSpeed
	);

	return;
}

E_CameraWorkID CameraWorkNormal::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkNormal::isEnd(void)
{
	return m_isEnd;
}

const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;

	//�E�X�e�B�b�N�̓|�ꂽ�������擾����
	gsXBoxPadGetRightAxis(0, &velocity);

	return velocity;
}

void CameraWorkNormal::resetCamera(void)
{
	//�E�X�e�B�b�N���������܂ꂽ��
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT_THUMB))
	{
		//�J�������v���C���[�̌��Ɉړ�
		m_rotate->x = 20;
		m_rotate->y = AMath::normalizeAngle(m_camera->get_direction_player() + 180);
	}
}
