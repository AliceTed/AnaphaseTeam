/**
@file AnimationSplineData.h
@brief �X�v���C���A�j���[�V�����i�[
@author Yuuho Aritomi
@date 2016/12/19
*/
#pragma once

#include <map>
#include <vector>
#include <memory>
#include <GSvector3.h>
#include <string>

class SplineVec3;
class AnimationSpline;

class AnimationSplineData
{
public:
	//�R���X�g���N�^
	AnimationSplineData(void);

	//�f�X�g���N�^
	~AnimationSplineData();

	/**
	@brief �ǂݍ��ݏ���
	@param[_id]		�h�c
	@param[_points] �e�_
	*/
	void add(std::string _id, const std::vector<GSvector3>& _points);
	/**
	@brief �ǂݍ��ݏ���
	@param[_id]			�h�c
	@param[_fileName]	�t�@�C����������OK
	*/
	void add(std::string _id, const std::string _fileName);

	/**
	@brief �w�肵���h�c�̃X�v���C���A�j���[�V���������s
	@param[_id]		ID
	@param[_speed]	���s���x
	@param[_center] ���_
	@return ���߂��ʒu�@�{�@���_
	*/
	AnimationSpline* get(std::string _id);

private:
	using AnimationSplineMap = std::map<std::string, std::unique_ptr<AnimationSpline>>;

	AnimationSplineMap m_datas;
};