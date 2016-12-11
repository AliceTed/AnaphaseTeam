/**
@file	CWParameterReader.h
@brief	�J�������[�N�̃p�����[�^���O������ǂݍ���
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <string>
#include <list>

class CWParameterReader
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_fileName] �t�@�C���̖��O
	*/
	CWParameterReader(const std::string _fileName);

	//�f�X�g���N�^
	~CWParameterReader();

	/**
	@brief	�擾
			�w�肵���v�f�����Ȃ���΃G���[���ƂO��Ԃ�
	@param[_index] �v�f��
	@return ���l
	*/
	float get(const int _index);

	/**
	@brief �z�񉉎Z�q�I�[�o���[�h
	@param[_index] �v�f��
	@return ���l
	*/
	float operator[](int _index);

private:
	//�ǂݍ��ݏ���
	void read(const std::string _fileName);

private:
	using Parameter = std::list<float>;
	using Parameter_Itr = Parameter::iterator;

	Parameter m_parameters;
};