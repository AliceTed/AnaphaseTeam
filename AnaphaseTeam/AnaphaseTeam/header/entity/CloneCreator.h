#pragma once
#ifndef _CLONECREATOR_H_
#define _CLONECREATOR_H_
/**
* @file CloneCreator.h
* @brief 汎用Factoryテンプレートクラスを使ったクローン生成用の関数オブジェクト
* @author 松尾裕也
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
		* @brief クローンの作成
		* @return 作成したクローン
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
