/**
@file 
.h
@brief �J����
@author Yuuoh Aritomi : Matuo
@date 2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"
class Camera
{
	Perspective m_perspective;
	LookAt m_look_at;

	//float m_near;
	//float m_far;

	float range_Position;
	float range_Eye;
	GSvector3 offset;
	GSvector3 position;

public:
	/**
	@brief �f�t�H���g�R���X�g���N�^
	*/
	Camera(void);

	/**
	@brief �R���X�g���N�^
	*/
	Camera(const Perspective* _perspective, const GSvector3* _position);

	/**
	@brief �R���X�g���N�^
	*/
	Camera(float range_Position, float range_Eye, const GSvector3& offset);

	/**
	@brief �f�X�g���N�^
	*/
	~Camera();

	/**
	@brief �X�V����
	@author Aritomi
	*/
	void update(void);

	/**
	@brief �w�肵���ʒu�Ɉړ�����
	@author Aritomi
	*/
	void move(const GSvector3* _position);

	/**
	@brief �J���������Ă���ʒu��ݒ肷��
	@author Aritomi
	*/
	void look_at(const GSvector3* _target);

	/** 
	@brief �p�[�X�y�N�e�B�u�l��Ԃ�
	@author Aritomi
	*/
	const Perspective PERSPECTIVE(void) const
	{
		return m_perspective;
	}

	/**
	@brief ���݂̃J�����̈ʒu��Ԃ�
	@author Aritomi
	*/
	const GSvector3 POSITION(void) const
	{
		return m_look_at.position;
	}

	/**
	@brief ���݂̒����_�̈ʒu��Ԃ�
	@author Aritomi
	*/
	const GSvector3 TARGET(void) const
	{
		return m_look_at.target;
	}

	/**
	@author Matuo
	*/
	void lookAt(const GSvector3& target, float dir);

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
	void update_perspective(const Perspective*) const;	// ���ߖ@�ݒ���X�V
	
	void update_look_at(const LookAt*) const;			// �\���ʒu���X�V
};