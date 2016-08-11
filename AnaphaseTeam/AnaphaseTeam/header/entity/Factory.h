#pragma once
#ifndef _FACTORY_H_
#define _FACTORY_H_
/**
* @file Factor.h
* @brief �ėpFactory�e���v���[�g�N���X
* @author �����T��
* @date 2016/8/02
*/
#include <unordered_map>

namespace Entity
{
	template
		<
		//�쐬���鐻�i
		typename AbstractProduct,
		//���iID
		typename ProductID = unsigned int,
		//���i�̍쐬�Ҋ֐�
		typename ProductCreator = AbstractProduct* (*)()
		>
	class Factory
	{
	public:
		/**
		* @fn
		* @brief ���i�̍쐬�҂�ǉ�
		* @param (_id) ���iID
		* @param (_creator) ���i�̍쐬�Ҋ֐�
		*/
		void registerProductCreator(const ProductID& _id, const ProductCreator& _creator)
		{
			m_Container.insert(std::make_pair(_id, _creator));
		}
		/**
		* @fn
		* @brief ���i�̍쐬�҂��폜
		* @param (_id) ���iID
		*/
		void unregisterProductCreator(const ProductID& _id)
		{
			m_Container.erase(id);
		}
		/**
		* @fn
		* @brief ���i�̍쐬
		* @param (_id) ���iID
		* @return �쐬�������i
		*/
		AbstractProduct* create(const ProductID& _id)
		{
			return m_Container.at(_id)();
		}

	private:
		//!���i�R���e�i�N���X
		typedef std::unordered_map<ProductID, ProductCreator> ProductContainer;
		//!���i�R���e�i
		ProductContainer m_Container;
	};
}
#endif // !_FACTORY_H_
