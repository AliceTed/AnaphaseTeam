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
	mLookAt(std::make_unique<LookAt>()),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	mPerspective->init(GSvector4(45.f, 1280.f / 720.f, 0.3f, 1000.f));
	mLookAt->init(GSvector3(0.f, 0.f, 0.f), GSvector3(0.f, 0.f, 0.f));
}

//�f�X�g���N�^
Camera::~Camera()
{
}

//���s
void Camera::run(IRenderer* _renderer)
{
	mPerspective->update();

	mLookAt->update();

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

//�n�ʂƂ̂����蔻��
void Camera::collisionGround(const Map & _map)
{
	mLookAt->collisionGround(_map);
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
	gsFrustumFromMatrices(&frustum, &mLookAt->matView(), &mPerspective->matProjective());

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

//�߃N���b�v�Ƃ̋���
const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohter�ƃJ�����̋���
	float dis = ohter.distance(mLookAt->position());
	//������near�̍�
	return dis-(mPerspective->near() + radius);
}

//�J�����Ƃ̋���
const float Camera::distance(const GSvector3 & ohter) const
{
	return mLookAt->distance(ohter);
}

//�J�����̃g�����X�t�H�[��
const Transform Camera::transform() const
{
	return mLookAt->transform();
}

//�J�����̈ʒu��Ԃ�
const GSvector3 & Camera::position(void)
{
	return mLookAt->position();
}

//�p�[�X�y�N�e�B�u���擾����
Perspective * Camera::perspective()
{
	return mPerspective.get();
}

//���b�N�A�b�g���擾����
LookAt * Camera::lookAt()
{
	return mLookAt.get();
}
