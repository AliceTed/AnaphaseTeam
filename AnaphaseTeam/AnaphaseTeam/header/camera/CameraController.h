/**
@file 
Controller.h
@brief �J�����𑀍삷��
@author Yuho Artiomi
@date 2016-08-28 Ver1.00
*/

#pragma once

#include <gslib.h>

class Camera;

class CameraController
{
	Camera *m_camera;		// �����������J����
	float m_distance;		// �^�[�Q�b�g�Ƃ̋���
	float m_pitch;			// �s�b�`
	float m_yow;			// ���[

public:
	/**
	@brief �f�t�H���g�R���X�g���N�^
	@param[_camera] ���삷��J����
	*/
	CameraController(Camera* _camera);

	/**
	@brief �R���X�g���N�^
	*/
	CameraController(Camera* _camera, const float _distance, const float _pitch, const float _yow);

	/**
	@brief ���삷��J�����̕ύX
	@param[_camera] ���삷��J����
	*/
	void change_control(Camera* _camera);

	/**
	@brief �w�肵���^�[�Q�b�g��ǔ�����
	@param[_speed]	
	[0~1]�͈̔͂Ŏw��
	0�̏ꍇ			:�ǔ��������Ȃ�
	0��1�ȊO�̏ꍇ	:�f�B���C�̕t�^���ꂽ�ǔ�
	1�̏ꍇ			:�f�B���C�̕t�^����Ȃ��ǔ�
	*/
	void follow(const GSvector3* _target, const float _speed);

	/**
	@brief ����ȓG�Ɛ키���p
	@param[_Target2] �����ɋ���ȓG�̃x�N�^�[��n����
	*/
	void special_move1(GSvector3* _target1, GSvector3* _target2, float _pitch, float _distance);

	/**
	@brief ���݂̃J�����̌�����Ԃ�
	*/
	const float DIRECTION(void) const;
};