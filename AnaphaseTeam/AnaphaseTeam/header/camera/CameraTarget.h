/**
@file CameraTarget.h
@brief �J�����̃^�[�Q�b�g
*/
#pragma once

#include <gslib.h>

class CameraTarget
{
public:
	/**
	@brief �R���X�g���N�^
	*/
	CameraTarget(void);

	/**
	@brief �f�X�g���N�^
	*/
	~CameraTarget();

	/**
	@brief �����_�ύX
	@param[_target] �^�[�Q�b�g
	*/
	void lookAt(const GSvector3& _target);

	/**
	@return �^�[�Q�b�g
	*/
	const GSvector3& _target(void) const;

private:
	GSvector3 m_target;	//�^�[�Q�b�g�ʒu
};