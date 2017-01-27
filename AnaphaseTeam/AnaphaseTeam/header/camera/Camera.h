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

class LookAt;		//�J�����̈ʒu���i�擪�̂r�͂��ɂ���ȁj
class CameraTarget;	//�J�����̃^�[�Q�b�g
class Map;			//�}�b�v�istd::map����Ȃ���j
class IRenderer;
class Zoom;

class Camera
{

public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	Camera();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~Camera();
	/**
	@fn
	@brief ���Z�b�g�I�t�Z�b�g
	*/
	void initializeOffset(void);
	/**
	@fn
	@brief �X�V����
	@param _renderer �����_���[
	*/
	void run(IRenderer* _renderer);
	/**
	@fn
	@brief	�e�B���g�E�p���J�������[�N
			�J�����̈ʒu�͌Œ肵���܂ܔ�ʑ̂�����
	@param _position_camera		�J�����̈ʒu
	@param _rotate				��]
								x��]���Œ肷��ƃe�B���g
								y��]���Œ肷��ƃp��
	@param _trackingSpeed		���x
								x�F�J�����̒ǔ����x
								y�F�^�[�Q�b�g�̒ǔ����x
	*/
	void tiltPan(
		const GSvector3&	_position_camera,
		const GSvector2&	_rotate,
		const GSvector2&	_trackingSpeed
	);
	/**
	@brief	�J�������[�N�E�h���[
	�^�[�Q�b�g�ɒǏ]����
	@param _position_target		�^�[�Q�b�g�ʒu
	@param _rotate				��]
	@param _distance			����
	@param _trackingSpeed		���x
								x�F�J�����̒ǔ����x
								y�F�^�[�Q�b�g�̒ǔ����x
	*/
	void dolly(
		const GSvector3&	_position_target,
		const GSvector2&	_rotate,
		const float			_distance,
		const GSvector2&	_trackingSpeed
	);
	/**
	@fn
	@brief �v���C���[�̈ʒu��ێ�
	@param _target	�v���C���[�̈ʒu�����Ă�
	*/
	void set_cameraTarget_player(const GSvector3& _target);
	/**
	@fn
	@brief �G�l�~�[�̈ʒu��ێ�
	@param _target	�G�l�~�[�̈ʒu�����Ă���
	*/
	void set_cameraTarget_enemy(const GSvector3& _target);
	/**
	@fn
	@brief �v���C���[�̕��ʊp��ێ�
	@param _direction	���ʊp
	*/
	void set_direction_player(float _direction);
	/**
	@fn
	@brief �J�������^�[�Q�b�g�ɒǔ�
	@param _target	�^�[�Q�b�g
	@param _speed	���x
					[0]			�ǔ�����
					[0 < x < 1] �f�B���C����̒ǔ�
					[1]			���S�ǔ�
	*/
	void tracking_position(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief �J�����I�t�Z�b�g���^�[�Q�b�g�ɒǔ�
	@param _target	�^�[�Q�b�g
	@param _speed 	���x
	[0]			�ǔ�����
	[0 < x < 1] �f�B���C����̒ǔ�
	[1]			���S�ǔ�
	*/
	void tracking_positionOffset(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief �����_���^�[�Q�b�g�ɒǔ�
	@param _target	�^�[�Q�b�g
	@param _speed	���x
					[0]			�ǔ�����
					[0 < x < 1] �f�B���C����̒ǔ�
					[1]			���S�ǔ�
	*/
	void tracking_lookAt(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief �����_�I�t�Z�b�g���^�[�Q�b�g�ɒǔ�
	@param _target  �^�[�Q�b�g
	@param _speed	���x
	[0]			�ǔ�����
	[0 < x < 1] �f�B���C����̒ǔ�
	[1]			���S�ǔ�
	*/
	void tracking_lookAtOffset(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief �n�ʂƂ̂����蔻��
	@param _map	�}�b�v
	*/
	void collisionGround(const Map& _map);
	/**
	@fn
	@brief �J�����^�[�Q�b�g���擾
	@return �J�����^�[�Q�b�g�i�v���C���[�j
	*/
	const GSvector3& get_cameraTarget_player(void) const;
	/**
	@fn
	@brief �J�����^�[�Q�b�g�����v����
	@return �J�����^�[�Q�b�g�i�G�l�~�[�j
	*/
	const GSvector3& get_cameraTarget_enemy(void) const;
	/**
	@fn
	@brief �v���C���[�̕��ʊp
	@return �v���C���[�̕��ʊp
	*/
	const float get_direction_player(void) const;
	/**
	@fn
	@brief �f���Ă��Ȃ����̂𒲂ׂ�
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;
	/**
	@fn
	@brief 
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;
	/**
	@fn
	@brief �J�����Ƃ̋���
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;
	/**
	@fn
	@brief �g�����X�t�H�[��
	@author Matuo
	*/
	const Transform transform()const;
	/**
	@brief �J�����̈ʒu
	@return �J�����̈ʒu
	*/
	const GSvector3& position(void);
	/**
	@fn
	@brief �Y�[��������n��
	@return �Y�[������
	*/
	Zoom* zoom();
private:
	// �J�����I�t�Z�b�g���^�[�Q�b�g�ɒǔ�
	void tracking_position_offset(const GSvector3& _target, float _speed = 1.0f);
	// �^�[�Q�b�g�I�t�Z�b�g���^�[�Q�b�g�ɒǔ�
	void tracking_target_offset(const GSvector3& _target, float _speed = 1.0f);
	//�J�����̎���p�Ɖ��ߏ����X�V
	void update_perspective(void);
	//�J�����̈ʒu�����X�V
	void update_lookAt(void);
	//�ǔ������X�V
	void update_tracking(
		const GSvector3& _position,
		const GSvector3& _lookAt,
		const GSvector2& _trackingSpeed);
	//�n�ʂƓ������Ă��邩�H
	bool isHitGround(const Map& _map, GSvector3* _position);
private:
	//���C�����ɔ�΂�
	const GSvector3					RAY_DONW;				
	//���a
	const float						R;						
	//����p�Ɖ��ߏ��
	GSvector4						m_perspective;			
	//�V�F�[�_�[�p���˕ϊ��s��
	GSmatrix4						m_mat_projection;		
	//�J�����̈ʒu���̏W����
	std::unique_ptr<LookAt>			m_lookAt;				
	//�h���[�������̃f�B���C�p�ϐ�
	GSvector2						m_rotate_dolly;			
	//�v���C���[�̈ʒu
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;	
	//�G�l�~�[�̈ʒu
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;	
	//�v���C���[�̕��ʊp
	float							m_direction_player;		
	//�ێ��p
	GSvector3						m_intersectPos;			
	//�Y�[��
	std::unique_ptr<Zoom>			mZoom;
};