#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/math/AMath.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera, GSvector2* _rotate) :
	CameraWorkEmpty(_camera),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkLockOn.cw")),
	m_rotate(_rotate),
	m_elevation(0.0f),
	m_distance(0.0f),
	m_distance_lockOn(0.0f),
	m_trackingSpeed(0.0, 0.0f),
	m_offset_value(0.0f),
	m_offset(0.0f)
{
	//�ǂݍ��񂾃p�����[�^���e�ϐ��ɑ��
	m_elevation			= (*m_parameter)[0];
	m_distance			= (*m_parameter)[1];
	m_distance_lockOn	= (*m_parameter)[2];
	m_trackingSpeed		= GSvector2(
		(*m_parameter)[3],
		(*m_parameter)[4]
	);
	m_offset_value		= (*m_parameter)[5];
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}

void CameraWorkLockOn::start(void)
{
	m_camera->initialize_zoom();

	m_nextCameraWork = "none";
	m_isEnd = false;
}

void CameraWorkLockOn::run(float _deltaTime)
{
	//�����ϐ����������������̂��߂�ǂ������̂�
	const GSvector3& player = m_camera->get_cameraTarget_player();
	const GSvector3& target = m_camera->get_cameraTarget_enemy();

	//�E������
	whichSide(player, target);

	//�v���C���[����^�[�Q�b�g�܂ł̃x�N�g�������߂�
	GSvector3 vector = AMath::vec3_vector(player, target);

	//�v���C���[�ƃ^�[�Q�b�g�̒��_�����߂�
	GSvector3 center = AMath::vec3_center(player, target);

	//�e����
	float distance_p_e = vector.length();						//�v���C���[����G�l�~�[�܂ł̋���
	float distance_p_c = gsVector3Distance(&player, &center);	//�v���C���[���璆�_�܂ł̋���

																//�J�����̈ʒu���v���C���[�ƒ��_�̑Ίp����ɂȂ�悤�ɍX�V
	update_toEleDir(vector, distance_p_c);

	//�J�������[�N�E�h���[�̏���
	m_camera->cameraWork_dolly(
		(center + m_offset_target),
		*m_rotate,
		distance_p_c + m_distance,
		m_trackingSpeed
	);

	return;
}

std::string CameraWorkLockOn::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkLockOn::isEnd(void)
{
	return m_isEnd;
}


void CameraWorkLockOn::update_toEleDir(const GSvector3& _vec, float _distance)
{
	//�v���C���[�G�l�~�[�̋��������l�Ȃ�����A���b�N�I������������
	if (_distance > m_distance_lockOn)
	{
		//�v���C���[����G�l�~�[�܂ł̋p�E���ʊp�����߂�
		gsVector3ToEleDir(&m_rotate->x, &m_rotate->y, &_vec);

		//���߂����l�𒲐�����
		m_rotate->x = m_elevation;		//�p�͌Œ肷��
		m_rotate->y += 180 + m_offset;	//���ʊp�͔��]���ăI�t�Z�b�g�𑫂�
	}
}

void CameraWorkLockOn::whichSide(const GSvector3 & _player, const GSvector3 & _target)
{
	//�e�_�̐ݒ�
	const GSvector2 p1 = GSvector2(_player.x, _player.z);							//���ꂪ���E�ǂ������ɂ��邩�𒲂ׂ�
	const GSvector2 p2 = GSvector2(m_camera->position().x, m_camera->position().z);	//�J�����̈ʒu
	const GSvector2 p3 = GSvector2(_target.x, _target.z);							//�^�[�Q�b�g�̈ʒu

	//���E�ǂ����ɂ��邩�𒲂ׂ�
	int n = AMath::side(p1, p2, p3);

	//n = 0�Ȃ�E�An = 1�Ȃ�E�An = 2�Ȃ獶�ɂ��炷
	if (n >= 0)
	{
		m_offset = m_offset_value;
	}
	else
	{
		m_offset = -m_offset_value;
	}
}
