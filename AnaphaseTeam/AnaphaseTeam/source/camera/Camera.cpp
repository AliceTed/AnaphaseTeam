#include "camera/Camera.h"
#include "camera/CameraTarget.h"
#include "math/Calculate.h"
#include "math/AMath.h"
#include "data/id/OCTREE_ID.h"
#include "map/Map.h"
#include "camera/LookAt.h"
#include "renderer/IRenderer.h"
#include "camera/Perspective.h"
#include "camera/Zoom.h"
#include "function/Tracking.h"
#include <random>
#include <vector>

//�R���X�g���N�^
Camera::Camera() :
	RAY_DONW(GSvector3(0, -1, 0)),
	R(0.5f),
	mPerspective(std::make_unique<Perspective>()),
	m_lookAt(std::make_unique<LookAt>(GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 1.0f, 0.0f))),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	mPerspective->init(GSvector4(45.f, 1280.f / 720.f, 0.3f, 1000.f));
}

//�f�X�g���N�^
Camera::~Camera()
{
}

//�������F�I�t�Z�b�g
void Camera::initializeOffset(void)
{
	m_lookAt->position_offset = { 0.0f, 0.0f, 0.0f };
	m_lookAt->target_offset = { 0.0f, 0.0f, 0.0f };
}

//���s
void Camera::run(IRenderer* _renderer)
{
	mPerspective->update();

	update_lookAt();
	//_renderer->lookAt(m_lookAt->position, m_lookAt->target, m_lookAt->up);

	return;
}

//�J�������[�N�F�e�B���g�E�p��
void Camera::tiltPan(
	const GSvector3&	_position_camera,
	const GSvector2&	_rotate,
	const GSvector2&	_trackingSpeed
)
{
	move(_position_camera, _trackingSpeed.x);

	lookAt(AMath::ballRotate(m_lookAt->position, _rotate, 10), _trackingSpeed.y);
}

//�J�������[�N�F�h���[
void Camera::dolly(
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
	GSvector3 position = AMath::ballRotate(
		_position_target,
		AMath::to_rad(m_rotate_dolly),
		_distance
	);

	move(position, _trackingSpeed.x);

	lookAt(_position_target, _trackingSpeed.y);

	return;
}

//�ݒ�F�J�����̈ʒu
void Camera::set_cameraTarget_player(const GSvector3& _target)
{
	//�v���C���[�̈ʒu��ێ�
	m_cameraTarget_player->lookAt(_target);
}

//�ݒ�F�^�[�Q�b�g�̈ʒu
void Camera::set_cameraTarget_enemy(const GSvector3& _target)
{
	//�G�l�~�[�̈ʒu��ێ�
	m_cameraTarget_enemy->lookAt(_target);
}

//�ݒ�F�v���C���[�̕��ʊp
void Camera::set_direction_player(float _direction)
{
	//�v���C���[�̕��ʊp��ێ�
	m_direction_player = _direction;
}

//�ǔ��F�J�����̈ʒu
void Camera::move(const GSvector3& _target, float _speed)
{
	GSvector3* position = &m_lookAt->position;
	Tracking::tracking(position, _target, _speed);
}

//�ǔ��F�����_
void Camera::lookAt(const GSvector3& _target, float _speed)
{
	GSvector3* target = &m_lookAt->target;
	Tracking::tracking(target, _target, _speed);
}

//�n�ʂƂ̂����蔻��
void Camera::collisionGround(const Map & _map)
{
	if (isHitGround(_map, &m_lookAt->position))
	{
		m_lookAt->position.y = m_intersectPos.y;
	}
}

//�擾�F�v���C���[�ʒu
const GSvector3& Camera::get_cameraTarget_player() const
{
	return m_cameraTarget_player->_target();
}

//�擾�F�G�̈ʒu
const GSvector3& Camera::get_cameraTarget_enemy() const
{
	return m_cameraTarget_enemy->_target();
}

//�擾�F�v���C���[�̕��ʊp
const float Camera::get_direction_player(void) const
{
	return m_direction_player;
}

//�����ĂȂ��I�u�W�F�N�g�͕`�悵�Ȃ�
const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	//������
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt->mat_view, &mPerspective->matProjective());

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

//�߃N���b�v�Ƃ̋���
const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohter�ƃJ�����̋���
	float dis = ohter.distance(m_lookAt->position);
	//������near�̍�
	return dis-(mPerspective->near() + radius);
}

//�J�����Ƃ̋���
const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt->position.distance(ohter);
}

//�J�����̃g�����X�t�H�[��
const Transform Camera::transform() const
{
	GSvector3 position = m_lookAt->position;
	//yaw��]����
 	GSvector3 vec= m_lookAt->target - position;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), position);
}

//�J�����̈ʒu��Ԃ�
const GSvector3 & Camera::position(void)
{
	return m_lookAt->position;
}

Perspective * Camera::perspective()
{
	return mPerspective.get();
}

//�ǔ��F�J�����̈ʒu�̃I�t�Z�b�g
void Camera::moveOffset(const GSvector3 & _target, float _speed)
{
	GSvector3* position = &m_lookAt->position_offset;
	Tracking::tracking(position, _target, _speed);
}

//�ǔ��F�����_�̃I�t�Z�b�g
void Camera::lookAtOffset(const GSvector3 & _target, float _speed)
{
	GSvector3* position = &m_lookAt->target_offset;
	Tracking::tracking(position, _target, _speed);
}

//���b�N�A�b�g�̍X�V
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
}

//�n�ʂƓ����������H
bool Camera::isHitGround(const Map& _map, GSvector3 * _position)
{
	GSvector3 intersectPos;

	if (_map.isCollisionRay((*_position), RAY_DONW, &intersectPos)) {
		m_intersectPos = intersectPos + GSvector3(0, R, 0);
	}
	
	if (m_intersectPos.y > m_lookAt->position.y) {
		return true;
	}

	return false;
}