#pragma once
#ifndef _LOADERROR_H_
#define _LOADERROR_H_
#include <string>
#include <gslib.h>
namespace Data
{
	class ErrorMessage
	{
	public:
		/**
		* @fn
		* @brief ���b�Z�[�W�{�b�N�X�Ń��b�Z�[�W��\��
		* @param (_fileName) �G���[���ł��t�@�C���̖��O
		* @param (_dataName) �f�[�^�̎��
		*/
		void operator ()(const std::string& _fileName, const std::string& _dataName)const;
	};
	class LoadError
	{
	public:
		/**
		* @fn
		* @brief �������Ȃ��������Ɏw��֐������s
		* @param (_isComplete) ����������
		* @param (_func)�������Ȃ��������ɌĂ΂��֐�
		*/
		template<class Func>
		void operator ()(BOOL _isComplete, Func _func)const
		{
			if (_isComplete)return;
			_func();
		}
	};
}

#endif