/**
@file
@brief �Y�[���N���X
@author Yuuho Aritomi
@date 2017/01/27
*/
#pragma once

/**
@class
@brief �Y�[���N���X
*/
class Zoom
{
public:
	/**
	@fn
	@brief �f�t�H���g�R���X�g���N�^
	*/
	Zoom();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~Zoom();
	/**
	@fn 
	@brief ������
	@param _zoom�Y�[���l
	*/
	void init(const float _zoom);
	/**
	@fn
	@brief �X�V
	@param _zoom ���̎Q�ƒl�ɃY�[���l��������
	*/
	void update(float* _zoom);
	/**
	@fn
	@brief �Y�[���C��
	@param _speed �Y�[���C�����x
	*/
	void zoomIN(const float _speed);
	/**
	@fn
	@brief �Y�[���A�E�g
	@param _speed �Y�[���A�E�g���x
	*/
	void zoomOut(const float _speed);
	/**
	@fn
	@brief �Y�[���ł���͈͂����肷��
	@param _min �Y�[���ł���ŏ��l
	@param _max �Y�[���ł���ő�l
	*/
	void clamp(float _min, float _max);
private:
	float mZoomValue;
};