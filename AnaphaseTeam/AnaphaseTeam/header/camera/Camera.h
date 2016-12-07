/************************************************************
@file	Camera.h
@brief	�J����
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
************************************************************/
#pragma once

#include <gslib.h>
#include <memory>

#include "../../header/transform/Transform.h"

typedef GSvector4 Perspective;

class CameraTarget;
class Map;

class Camera
{

public:
	/********************************************************
	@brief �R���X�g���N�^
	********************************************************/
	Camera(Map* _map);


	/********************************************************
	@brief �f�X�g���N�^
	********************************************************/
	~Camera();


	/********************************************************
	@brief �Y�[���֌W������
	********************************************************/
	void initialize_zoom(void);


	/********************************************************
	@brief �X�V����
	********************************************************/
	void update(void);


	/********************************************************
	@brief �w�肵���ʒu�Ɉړ�����
	@param[_position] �ʒu
	********************************************************/
	void move(const GSvector3& _position);


	/********************************************************
	@brief �J���������Ă���ʒu��ݒ肷��
	@param[_target] �^�[�Q�b�g
	********************************************************/
	void lookAt(const GSvector3& _target);


	/********************************************************
	@brief	�e�B���g�E�p���J�������[�N
			�J�����̈ʒu�͌Œ肵���܂ܔ�ʑ̂�����
	@param[_position_camera]	�J�����̈ʒu
	@param[_rotate]				��]
								x��]���Œ肷��ƃe�B���g
								y��]���Œ肷��ƃp��
	@param[_followSpeed_camera]	�J�����̒ǔ����x
	@param[_followSpeed_target]	�^�[�Q�b�g�̒ǔ����x
	********************************************************/
	void cameraWork_tilt_pan(
		const GSvector3& _position_camera,
		GSvector2 _rotate,
		const float _followSpeed_camera,
		const float _followSpeed_target
	);


	/********************************************************
	@brief	�J�������[�N�E�h���[
	�^�[�Q�b�g�ɒǏ]����
	@param[_position_target]	�^�[�Q�b�g�ʒu
	@param[_elevation]			�p
	@param[_direction]			���ʊp
	@param[_distance]			����
	@param[_followSpeed_camera]	�J�����̒ǔ����x
	@param[_followSpeed_target] �^�[�Q�b�g�̒ǔ����x
	********************************************************/
	void cameraWork_dolly(
		const GSvector3&	_position_target,
		GSvector2			_rotate,
		const float			_distance,
		const float			_followSpeed_camera,
		const float			_followSpeed_target
	);


	/********************************************************
	@brief �v���C���[�̈ʒu��ێ�
	@param[_target] �v���C���[�̈ʒu�����Ă�
	********************************************************/
	void lookAt_cameraTarget_player(const GSvector3& _target);


	/********************************************************
	@brief �G�l�~�[�̈ʒu��ێ�
	@param[_target] �G�l�~�[�̈ʒu�����Ă���
	********************************************************/
	void lookAt_cameraTarget_enemy(const GSvector3& _target);


	/********************************************************
	@brief �J�������^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
					[0] �ǔ�����
					[1] �f�B���C����̒ǔ�
					[2] ���S�ǔ�
	********************************************************/
	void follow_position(const GSvector3& _target, const float _speed);


	/********************************************************
	@brief �����_���^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
	[0] �ǔ�����
	[1] �f�B���C����̒ǔ�
	[2] ���S�ǔ�
	********************************************************/
	void follow_target(const GSvector3& _target, const float _speed);


	/********************************************************
	@brief �g��͈͂�ݒ�
	@param[_min] �ŏ��l
	@param[_max] �ő�l
	********************************************************/
	void zoom_clamp(
		const float _min,
		const float _max
	);


	/********************************************************
	@brief �Y�[��
	@param[_value] �l
	********************************************************/
	void zoom(const float _value);


	/********************************************************
	@brief �Y�[���C��
	@param[_speed] ���x
	********************************************************/
	void zoom_in(const float _speed);


	/********************************************************
	@brief �Y�[���A�E�g
	@param[_speed] ���x
	********************************************************/
	void zoom_out(const float _speed);


	/********************************************************
	@return �J�����^�[�Q�b�g�i�v���C���[�j
	********************************************************/
	const GSvector3& cameraTarget_player(void) const;

	/********************************************************
	@return �J�����^�[�Q�b�g�i�G�l�~�[�j
	********************************************************/
	const GSvector3& cameraTarget_enemy(void) const;

	/**
	@author Matuo
	*/
	//void lookAt(const GSvector3& target, float dir);

	/**
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;

	/**
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;

	/**
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;

	//��肠����
	const Transform transform()const;

private:
	void update_perspective(void);

	void update_lookAt(void);

	void update_zoom(const float _speed);

	void hit_ground(GSvector3* _position);

	bool collisionRay_octree(
		GSvector3* _intersectPos, 
		const GSvector3& _position, 
		const GSvector3& _rayDir
	);

private:
	static const GSvector3			RAY_DONW;

	static const float				DEF_FOV_MIN;
	static const float				DEF_FOV_MAX;

	Map*							m_map;

	Perspective						m_perspective;
	float							m_def_fov;
	float							m_fov_min;
	float							m_fov_max;
	GSmatrix4						m_matProjection;

	GSvector3						m_position;
	GSvector3						m_target;
	GSvector3						m_up;
	GSmatrix4						m_matView;

	GSvector2						m_rotate_dolly;

	std::shared_ptr<CameraTarget>	m_cameraTarget_player;
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;
};