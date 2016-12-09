/**
@file	Camera.h
@brief	�J����
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "../../header/transform/Transform.h"

class SLookAt;		//�J�����̈ʒu���i�擪�̂r�͂��ɂ���ȁj
class CameraTarget;	//�J�����̃^�[�Q�b�g
class Map;			//�}�b�v�istd::map����Ȃ���j

class Camera
{

public:
	/**
	@brief �R���X�g���N�^
	*/
	Camera(Map* _map);


	/**
	@brief �f�X�g���N�^
	*/
	~Camera();


	/**
	@brief �Y�[���֌W������
	*/
	void initialize_zoom(void);


	/**
	@brief �X�V����
	*/
	void update(void);


	/**
	@brief	�e�B���g�E�p���J�������[�N
			�J�����̈ʒu�͌Œ肵���܂ܔ�ʑ̂�����
	@param[_position_camera]	�J�����̈ʒu
	@param[_rotate]				��]
								x��]���Œ肷��ƃe�B���g
								y��]���Œ肷��ƃp��
	@param[_trackingSpeed]		���x
								x�F�J�����̒ǔ����x
								y�F�^�[�Q�b�g�̒ǔ����x
	*/
	void cameraWork_tilt_pan(
		const GSvector3&	_position_camera,
		const GSvector2&	_rotate,
		const GSvector2&	_trackingSpeed
	);


	/**
	@brief	�J�������[�N�E�h���[
	�^�[�Q�b�g�ɒǏ]����
	@param[_position_target]	�^�[�Q�b�g�ʒu
	@param[_rotate]				��]
	@param[_distance]			����
	@param[_trackingSpeed]		���x
								x�F�J�����̒ǔ����x
								y�F�^�[�Q�b�g�̒ǔ����x
	*/
	void cameraWork_dolly(
		const GSvector3&	_position_target,
		const GSvector2&	_rotate,
		const float			_distance,
		const GSvector2&	_trackingSpeed
	);


	/**
	@brief �v���C���[�̈ʒu��ێ�
	@param[_target] �v���C���[�̈ʒu�����Ă�
	*/
	void lookAt_cameraTarget_player(const GSvector3& _target);


	/**
	@brief �G�l�~�[�̈ʒu��ێ�
	@param[_target] �G�l�~�[�̈ʒu�����Ă���
	*/
	void lookAt_cameraTarget_enemy(const GSvector3& _target);


	/**
	@brief �J�������^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
					[0]			�ǔ�����
					[0 < x < 1] �f�B���C����̒ǔ�
					[1]			���S�ǔ�
	*/
	void tracking_position(const GSvector3& _target, float _speed = 1.0f);


	/**
	@brief �����_���^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
					[0]			�ǔ�����
					[0 < x < 1] �f�B���C����̒ǔ�
					[1]			���S�ǔ�
	*/
	void tracking_lookAt(const GSvector3& _target, float _speed = 1.0f);


	/**
	@brief �g��͈͂�ݒ�
	@param[_min] �ŏ��l
	@param[_max] �ő�l
	*/
	void zoom_clamp(
		const float _min,
		const float _max
	);


	/**
	@brief �Y�[��
	@param[_value] �l
	*/
	void zoom(const float _value);


	/**
	@brief �Y�[���C��
	@param[_speed] ���x
	*/
	void zoom_in(const float _speed);


	/**
	@brief �Y�[���A�E�g
	@param[_speed] ���x
	*/
	void zoom_out(const float _speed);


	/**
	@return �J�����^�[�Q�b�g�i�v���C���[�j
	*/
	const GSvector3& cameraTarget_player(void) const;

	/**
	@return �J�����^�[�Q�b�g�i�G�l�~�[�j
	*/
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

	/**
	@author Matuo
	*/
	const Transform transform()const;

	/**
	@return �J�����̈ʒu
	*/
	const GSvector3& position(void);

private:
	//�J�����̎���p�Ɖ��ߏ����X�V
	void update_perspective(void);

	//�J�����̈ʒu�����X�V
	void update_lookAt(void);

	//�J�����̃Y�[���l���X�V
	void update_zoom(const float _speed);

	//�ǔ������X�V
	void update_tracking(
		const GSvector3& _position,
		const GSvector3& _lookAt,
		const GSvector2& _trackingSpeed);

	//�n�ʂƂ̂����蔻��
	void hit_ground(GSvector3* _position);

	//�n�ʂƓ������Ă��邩�H
	bool isHitGround(GSvector3 * _intersectPos, GSvector3* _position);


private:
	using Perspective = GSvector4;							//�S�����x�N�g�����p�[�X�y�N�e�B�u�Ƃ��Đݒ�

	static const GSvector3			RAY_DONW;				//���C�����ɔ�΂�

	static const float				DEF_FOV;				//����p�̃f�t�H���g�l
	static const GSvector2			DEF_FOV_CLAMP;			//����p�͈̔͂̃f�t�H���g�l

	Map*							m_map;					//�}�b�v

	Perspective						m_perspective;			//����p�Ɖ��ߏ��
	GSvector2						m_fov_clamp;			//����p�͈̔�
	GSmatrix4						m_mat_projection;		//�V�F�[�_�[�p���˕ϊ��s��

	std::unique_ptr<SLookAt>		m_lookAt;				//�J�����̈ʒu���̏W����

	GSvector2						m_rotate_dolly;			//�h���[�������̃f�B���C�p�ϐ�

	std::shared_ptr<CameraTarget>	m_cameraTarget_player;	//�v���C���[�̈ʒu
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;	//�G�l�~�[�̈ʒu
};