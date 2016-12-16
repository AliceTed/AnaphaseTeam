#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"
#include "../../header/math/Calculate.h"
#include "../../header/math/AMath.h"
#include "../../header/data/id/OCTREE_ID.h"
#include "../../header/map/Map.h"
#include "../../header/camera/SLookAt.h"
#include <random>

const GSvector3 Camera::RAY_DONW = GSvector3(0, -1, 0);		//���C�͉��ɔ�΂������̂ł�������-1����

const float Camera::DEF_FOV				= 45.0f;			//����p�̃f�t�H���g�l��45�x�ŌŒ�
const GSvector2 Camera::DEF_FOV_CLAMP	= { 2.0f, 180.0f };	//����p�͈̔͂�2.0~180.0�͈̔�

Camera::Camera() :
	m_perspective(GSvector4(DEF_FOV, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	m_fov_clamp(DEF_FOV_CLAMP.x, DEF_FOV_CLAMP.y),
	m_lookAt(std::make_unique<SLookAt>(GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 1.0f, 0.0f))),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	//���e�ϊ��s��̏�����
	gsMatrix4Identity(&m_mat_projection);
}

Camera::~Camera()
{
}

void Camera::initialize_zoom(void)
{
	//����p��������
	m_perspective.x	= DEF_FOV;
	//����p�̎w��͈͂�������
	m_fov_clamp.x		= DEF_FOV_CLAMP.x;
	m_fov_clamp.y		= DEF_FOV_CLAMP.y;
}

void Camera::reset_offset(void)
{
	m_lookAt->position_offset = { 0.0f, 0.0f, 0.0f };
	m_lookAt->target_offset = { 0.0f, 0.0f, 0.0f };
}

void Camera::update(void)
{
	//����p�E���ߏ����X�V
	update_perspective();

	//�J�����ʒu�����X�V
	update_lookAt();

	return;
}

void Camera::cameraWork_tilt_pan(
	const GSvector3&	_position_camera,
	const GSvector2&	_rotate,
	const GSvector2&	_trackingSpeed
)
{
	//�ǔ������X�V
	update_tracking(
		_position_camera,
		AMath::rotate_sphericalCoordinates(m_lookAt->position, _rotate, 10),	//���ʍ��W�𗘗p������]
		_trackingSpeed
	);

	return;
}

void Camera::cameraWork_dolly(
	const GSvector3&	_position_target,
	const GSvector2&	_rotate,
	const float			_distance,
	const GSvector2&	_trackingSpeed
)
{
	//�p�ƕ��ʊp�̃��[�v
	AMath::lerp_eleDir(
		&m_rotate_dolly,
		_rotate,
		_trackingSpeed.x
	);

	//���ʍ��W���g������]
	GSvector3 position = AMath::rotate_sphericalCoordinates(
		_position_target,
		AMath::to_rad(m_rotate_dolly),
		_distance
	);

	//�ǔ������X�V
	update_tracking(
		position,
		_position_target,
		_trackingSpeed
	);

	return;
}

void Camera::set_cameraTarget_player(const GSvector3& _target)
{
	//�v���C���[�̈ʒu��ێ�
	m_cameraTarget_player->lookAt(_target);

	return;
}

void Camera::set_cameraTarget_enemy(const GSvector3& _target)
{
	//�G�l�~�[�̈ʒu��ێ�
	m_cameraTarget_enemy->lookAt(_target);

	return;
}

void Camera::set_direction_player(float _direction)
{
	//�v���C���[�̕��ʊp��ێ�
	m_direction_player = _direction;
}

void Camera::tracking_position(const GSvector3& _target, float _speed)
{
	//���₷�����邽�߂ɐ錾
	GSvector3* position = &m_lookAt->position;

	//�R�����x�N�g���̐��`���
	gsVector3Lerp(position, position, &_target, _speed);

	return;
}

void Camera::tracking_lookAt(const GSvector3& _target, float _speed)
{
	//���₷�����邽�߂ɐ錾
	GSvector3* target = &m_lookAt->target;

	//�R�����x�N�g���̐��`���
	gsVector3Lerp(target, target, &_target, _speed);

	return;
}

void Camera::collisionGround(const Map & _map)
{
	//����Ƀ��C�̃q�b�g�����ʒu���ێ������
	GSvector3 intersectPos;

	//�J�������n�ʂɓ������Ă�����
	//�J�����̈ʒu���C��
	if (isHitGround(_map, &intersectPos, &m_lookAt->position))
	{
		m_lookAt->position.y = intersectPos.y;
	}
}

void Camera::shake(GSvector2 _scale)
{
	GSvector3 position;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randX(0, _scale.x);
	std::uniform_int_distribution<> randY(0, _scale.y);
	float x = cos(randX(mt));
	float y = sin(randY(mt));

	position.x = cos(randX(mt));
	position.y = sin(randY(mt));
	position.z = 0;

	tracking_position_offset(position, 0.1f);
	tracking_target_offset(position, 0.1f);

	return;
}

void Camera::zoom_clamp(
	const float _min,
	const float _max
)
{
	//����p�͈̔͂��Đݒ�
	m_fov_clamp.x = _min;
	m_fov_clamp.y = _max;

	return;
}

void Camera::zoom(const float _value)
{
	//����p���Đݒ�
	m_perspective.x = _value;
}

void Camera::zoom_in(const float _speed)
{
	//�Y�[�������X�V
	update_zoom(-_speed);
}

void Camera::zoom_out(const float _speed)
{
	//�Y�[�������X�V
	update_zoom(_speed);
}

const GSvector3& Camera::get_cameraTarget_player() const
{
	//�ێ������v���C���[�̈ʒu��Ԃ�
	return m_cameraTarget_player->_target();
}

const GSvector3& Camera::get_cameraTarget_enemy() const
{
	//�ێ������G�l�~�[�̈ʒu��Ԃ�
	return m_cameraTarget_enemy->_target();
}

const float Camera::get_direction_player(void) const
{
	return m_direction_player;
}

const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	//������
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt->mat_view, &m_mat_projection);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohter�ƃJ�����̋���
	float dis = ohter.distance(m_lookAt->position);
	//������near�̍�
	return dis-(m_perspective.z + radius);
}

const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt->position.distance(ohter);
}

const Transform Camera::transform() const
{
	GSvector3 position = m_lookAt->position;
	//yaw��]����
 	GSvector3 vec= m_lookAt->target - position;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), position);
}

const GSvector3 & Camera::position(void)
{
	//�J�����̈ʒu��Ԃ�
	return m_lookAt->position;
}

void Camera::tracking_position_offset(const GSvector3 & _target, float _speed)
{
	//���₷�����邽�߂ɐ錾
	GSvector3* position = &m_lookAt->position_offset;

	//�R�����x�N�g���̐��`���
	gsVector3Lerp(position, position, &_target, _speed);
}

void Camera::tracking_target_offset(const GSvector3 & _target, float _speed)
{
	//���₷�����邽�߂ɐ錾
	GSvector3* position = &m_lookAt->target_offset;

	//�R�����x�N�g���̐��`���
	gsVector3Lerp(position, position, &_target, _speed);
}

void Camera::update_perspective(void)
{
	//���˕ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);

	//�ϊ��s��̏�����
	glLoadIdentity();

	//���˕ϊ��s��
	gluPerspective(
		m_perspective.x,
		m_perspective.y,
		m_perspective.z,
		m_perspective.w
	);

	//�V�F�[�_�[�p���˕ϊ��s��Ɍ��݂̓��˕ϊ��s�����
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&m_mat_projection);

	return;
}

void Camera::update_lookAt(void)
{
	//���f���r���[�ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);

	//���f���r���[�ϊ��s��̏�����
	glLoadIdentity();

	//��������m_lookAt�ĂԂ̂��߂�ǂ������̂Ő錾
	GSvector3 position	= m_lookAt->position + m_lookAt->position_offset;
	GSvector3 target	= m_lookAt->target + m_lookAt->target_offset;
	GSvector3 up		= m_lookAt->up;

	//���f���r���[�ϊ��s��
	gluLookAt(
		position.x,	position.y,	position.z,
		target.x,	target.y,	target.z,
		up.x,		up.y,		up.z
	);

	//�V�F�[�_�[�p���f���r���[�ϊ��s��Ɍ��݂̃��f���r���[�s�����
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&m_lookAt->mat_view);

	return;
}

void Camera::update_zoom(const float _value)
{
	Math::Clamp clamp;
	
	//����p�ɒl�𑫂�
	m_perspective.x += _value;

	//����p�̒l���͈͊O�ɏo�Ȃ��悤�ɂ���
	m_perspective.x = clamp(
		m_perspective.x,
		m_fov_clamp.x,
		m_fov_clamp.y
	);

	return;
}

void Camera::update_tracking(
	const GSvector3 & _position,
	const GSvector3 & _lookAt,
	const GSvector2 & _trackingSpeed)
{
	//�J�����ʒu�̒ǔ�����
	tracking_position(_position, _trackingSpeed.x);

	//�����_�̒ǔ�����
	tracking_lookAt(_lookAt, _trackingSpeed.y);
}

bool Camera::isHitGround(const Map& _map, GSvector3 * _intersectPos, GSvector3 * _position)
{
	//�J�������n�ʂɓ������Ă��邩�𒲂ׂ�
	return _map.isCollisionRay((*_position), RAY_DONW, _intersectPos) &&
		_position->y < _intersectPos->y;
}