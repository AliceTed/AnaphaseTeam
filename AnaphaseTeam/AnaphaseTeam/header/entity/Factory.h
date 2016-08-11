#pragma once
#ifndef _FACTORY_H_
#define _FACTORY_H_
/**
* @file Factor.h
* @brief 汎用Factoryテンプレートクラス
* @author 松尾裕也
* @date 2016/8/02
*/
#include <unordered_map>

namespace Entity
{
	template
		<
		//作成する製品
		typename AbstractProduct,
		//製品ID
		typename ProductID = unsigned int,
		//製品の作成者関数
		typename ProductCreator = AbstractProduct* (*)()
		>
	class Factory
	{
	public:
		/**
		* @fn
		* @brief 製品の作成者を追加
		* @param (_id) 製品ID
		* @param (_creator) 製品の作成者関数
		*/
		void registerProductCreator(const ProductID& _id, const ProductCreator& _creator)
		{
			m_Container.insert(std::make_pair(_id, _creator));
		}
		/**
		* @fn
		* @brief 製品の作成者を削除
		* @param (_id) 製品ID
		*/
		void unregisterProductCreator(const ProductID& _id)
		{
			m_Container.erase(id);
		}
		/**
		* @fn
		* @brief 製品の作成
		* @param (_id) 製品ID
		* @return 作成した製品
		*/
		AbstractProduct* create(const ProductID& _id)
		{
			return m_Container.at(_id)();
		}

	private:
		//!製品コンテナクラス
		typedef std::unordered_map<ProductID, ProductCreator> ProductContainer;
		//!製品コンテナ
		ProductContainer m_Container;
	};
}
#endif // !_FACTORY_H_
