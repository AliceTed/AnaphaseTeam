/**
@file	Camera.h
@brief	�J����
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "transform/Transform.h"
#include "camera/LookAt.h";
#include "camera/Perspective.h"

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
	@brief �X�V����
	@param _renderer �����_���[
	*/
	void run(IRenderer* _renderer);
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
	@brief �p�[�X�y�N�e�B�u���擾����
	@return �p�[�X�y�N�e�B�u
	*/
	Perspective* perspective();
	/**
	@fn
	@brief ���b�N�A�b�g���擾����
	@return ���b�N�A�b�g
	*/
	LookAt* lookAt();
private:
	//���C�����ɔ�΂�
	const GSvector3					RAY_DONW;				
	//���a
	const float						R;						
	//����p�Ɖ��ߏ��
	std::unique_ptr<Perspective>	mPerspective;			
	//�J�����̈ʒu���̏W����
	std::unique_ptr<LookAt>			mLookAt;				
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
};