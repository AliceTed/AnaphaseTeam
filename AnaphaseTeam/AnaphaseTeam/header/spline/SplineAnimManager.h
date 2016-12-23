/**
@file	SplineManager.h
@brief	�X�v���C���Ǘ���
@author Yuuho Aritomi
@date	2016/12/19
*/
#pragma once

#include <gslib.h>
#include <memory>
#include <string>

class AnimationSplineData;
class AnimationSpline;

class SplineAnimManager
{
public:
	//�R���X�g���N�^
	SplineAnimManager(void);

	//�f�X�g���N�^
	~SplineAnimManager();

	/**
	@brief �ǂݍ��ݏ���
	*/
	void load(void);

	/**
	@brief �A�j���[�V�����h�c��؂�ւ���
	@param[_id] �A�j���[�V�����h�c*/
	void changeID(std::string _id);


	AnimationSpline* get(std::string _id);

	/**
	@brief ���s
	@param[_speed]	���x
	@param[_center]	���_
	*/
	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

	/**
	@return �I���������H
	*/
	bool isEnd(void);

private:
	std::string m_currentID;

	std::unique_ptr<AnimationSplineData> m_datas;
};