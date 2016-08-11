#pragma once
#ifndef _CLONECREATOR_H_
#define _CLONECREATOR_H_
/**
* @file CloneCreator.h
* @brief �ėpFactory�e���v���[�g�N���X���g�����N���[�������p�̊֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/8/02
*/
#include <memory>
namespace Entity
{
	template
		<
		typename AbstractProduct,
		typename AbstractProduct* (AbstractProduct::*MemFun)() = &AbstractProduct::clone
		>
	class CloneCreator
	{
	public:
		CloneCreator(AbstractProduct* _creator = nullptr)
			:m_Creator(_creator)
		{}

		/**
		* @fn
		* @brief �N���[���̍쐬
		* @return �쐬�����N���[��
		*/
		AbstractProduct* operator () ()const
		{
			return (m_Creator.get()->*MemFun)();
		}

	private:
		std::shared_ptr<AbstractProduct>m_Creator;
	};
}
#endif // !_CLONECREATOR_H_
