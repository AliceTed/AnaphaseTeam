/**
@file
@brief	�p�[�X�y�N�e�B�u
@author Yuuho Aritomi
@date	2017/01/27
*/
#pragma once

#include <gslib.h>
#include <memory>

class IRenderer;
class Zoom;

/**
@file
@brief �p�[�X�y�N�e�B�u
*/
class Perspective
{
public:
	/**
	@fn
	@brief �f�t�H���g�R���X�g���N�^
	*/
	Perspective();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~Perspective();
	/**
	@fn
	@brief ������
	*/
	void init(const GSvector4& _perspective);
	/**
	@fn
	@brief �X�V
	*/
	void update();
	/**
	@fn
	@brief �X�V�i�����_���[�j
	@param _renderer �����_���[
	*/
	void update(IRenderer* _renderer);
	/**
	@fn
	@brief �p�[�X�y�N�e�B�u�l��Ԃ�
	@return �p�[�X�y�N�e�B�u�l
	*/
	GSvector4 perspective();
	/**
	@fn
	@brief �Y�[���@�\��n��
	@return �Y�[���@�\
	*/
	Zoom* zoom();
	/**
	@fn
	@brief ��ŏ���
	*/
	float near();
	/**
	@fn
	@brief ��ŏ���
	*/
	GSmatrix4 matProjective();
private:
	//����p�Ɖ��ߏ��
	GSvector4 mPerspective;
	//�V�F�[�_�[�p���˕ϊ��s��
	GSmatrix4 mMatProjection;
	//�Y�[���@�\
	std::unique_ptr<Zoom> mZoom;
};