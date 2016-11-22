/************************************************************
@file LookAt.h
@brief �J�����̈ʒu���
@author Yuuho Aritomi
@date 2016/11/20
************************************************************/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	/********************************************************
	@brief �R���X�g���N�^
	********************************************************/
	LookAt(void);



	/********************************************************
	@brief �R���X�g���N�^
	@param[_position]	�ʒu
	@param[_target]		�����_
	@param[_up]			�J�����̏����
	********************************************************/
	LookAt(
		const GSvector3& _position, 
		const GSvector3& _target, 
		const GSvector3& _up
	);



	/********************************************************
	@brief �f�X�g���N�^
	********************************************************/
	~LookAt();



	/********************************************************
	@brief ������
	@param[_position]	�ʒu
	@param[_target]		�����_
	@param[_up]			�J�����̏����
	********************************************************/
	void initialize(
		const GSvector3& _position,
		const GSvector3& _target,
		const GSvector3& _up
	);



	/********************************************************
	@brief �X�V����
	********************************************************/
	void update(void);



	/********************************************************
	@brief �ړ�����
	@param[_position] �ړ���
	********************************************************/
	void set_position(const GSvector3& _position);



	/********************************************************
	@brief ���s�ړ�
	@param[_vector] �ړ���
	********************************************************/
	void translate(const GSvector3& _vector);



	/********************************************************
	@brief ��ʑ̂�����
	@param[_target] �^�[�Q�b�g
	********************************************************/
	void lookAt(const GSvector3& _target);



	/********************************************************
	@brief �I�t�Z�b�g���܂߂Ĕ�ʑ̂�����
	@param[_target] �^�[�Q�b�g
	********************************************************/
	void lookAt_offset(const GSvector3& _target);



	/********************************************************
	@brief ������]�݂̂Ŕ�ʑ̂�����
	@param[_target] �^�[�Q�b�g
	@param[_direction] ���ʊp
	********************************************************/
	void lookAt_tilt(const GSvector3& _target, const float _direction);



	/********************************************************
	@brief	�e�B���g�J�������[�N
			x����]�݂̂Ŕ�ʑ̂�����
			�i�����ƊȒP�ɂ�������j
	@param[_position_camera]	�J�����̈ʒu
	@param[_position_target]	�^�[�Q�b�g�̈ʒu
	@param[_direction]			���ʊp
	@param[_followSpeed_camera] �J�����̒ǔ����x
	@param[_followSpeed_target]	�^�[�Q�b�g�̒ǔ����x
								[0] �ǔ�����
								[0.1~0.9] �f�B���C����̒ǔ�
								[1] ���S�ǔ�
	********************************************************/
	void cameraWork_tilt(
		const GSvector3& _position_camera,
		const GSvector3& _position_target,
		const float _direction,
		const float _followSpeed_camera,
		const float _followSpeed_target
	);



	/********************************************************
	@brief y����]�݂̂Ŕ�ʑ̂�����
	@param[_target]		�^�[�Q�b�g
	@param[_elevation]	�p
	********************************************************/
	void lookAt_pan(const GSvector3& _target, const float _elevation);



	/********************************************************
	@brief ��ʑ̂����邩���Ă���
	@param[_target]		�^�[�Q�b�g
	@param[_elevation]	�p
	@param[_direction]	���ʊp
	@param[_distance]	����
	********************************************************/
	void lookAt_dolly(
		const GSvector3&	_target, 
		const float			_elevation, 
		const float			_direction,
		const float			_distance
	);



	/********************************************************
	@brief 
	�J�����̈ʒu����^�[�Q�b�g�̈ʒu�܂ł�
	�p�A���ʊp�����߂�
	@param[_elevation] �p
	@param[_direction] ���ʊp
	********************************************************/
	void to_eleDir(float* _elevation, float* _direction);



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
	@return �ʒu
	********************************************************/
	const GSvector3& position(void) const
	{
		return m_position;
	}
	/********************************************************
	@return �^�[�Q�b�g
	********************************************************/
	const GSvector3& target(void) const
	{
		return m_target;
	}
	/********************************************************
	@return �J�����̏����
	********************************************************/
	const GSvector3& up(void) const
	{
		return m_up;
	}
	/********************************************************
	@return ���f���r���[�s��
	********************************************************/
	const GSmatrix4& matView(void) const
	{
		return m_matView;
	}
	/********************************************************
	@return �p
	********************************************************/
	const float elevation(void) const
	{
		return m_elevation;
	}
	/********************************************************
	@return ���ʊp
	********************************************************/
	const float direction(void) const
	{
		return m_direction;
	}

	private:
		void to_radEleDir(float* _elevation, float * _direction);

		void vector_p1_p2(
			GSvector3*			_vector, 
			const GSvector3&	_p1, 
			const GSvector3&	_p2
		);

	private:
		GSvector3	m_position;
		GSvector3	m_target;
		GSvector3	m_targetOffset;
		GSvector3	m_up;

		GSmatrix4	m_matView;

		float		m_elevation;
		float		m_direction;
};
