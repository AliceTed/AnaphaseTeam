#pragma once
#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_
/**
* @file EntityManager.h
* @brief 汎用テンプレートマネージャクラス
* @author 松尾裕也
* @date 2016/8/02
*/
//スマートポインタを格納すことを前提にしている
#include <list>

namespace Entity
{
	template<class Entity>
	class EntityManager
	{
	public:
		EntityManager();
		/**
		* @fn
		* @brief 要素を追加
		* @param (_entity)追加する要素
		*/
		void add(const Entity& _entity);

		/**
		* @fn
		* @brief 条件を満たす要素を削除
		* @param (_func)条件関数
		*/
		template<typename Func>void remove(Func _func);
		/**
		* @fn
		* @brief 各要素にアクセスする
		* @param (_func)アクセス内容
		*/
		template<typename Func>void accept(Func _func);
		/**
		* @fn
		* @brief 要素数
		*/
		const unsigned int size()const;
		/**
		* @fn
		* @brief 全ての要素を削除
		*/
		void clear();
	private:
		std::list<Entity> m_Container;
	};
}

#endif // !_ENTITYMANAGER_H_
namespace Entity
{
	template<class Entity>
	EntityManager<Entity>::EntityManager()
		:m_Container()
	{
	}

	template<class Entity>
	void EntityManager<Entity>::add(const Entity & entity)
	{
		m_Container.emplace_back(entity);
	}

	template<class Entity>
	const unsigned int EntityManager<Entity>::size() const
	{
		return static_cast<unsigned int>(m_Container.size());
	}

	template<class Entity>
	void EntityManager<Entity>::clear()
	{
		m_Container.clear();
	}

	template<class Entity>
	template<typename Func>
	void EntityManager<Entity>::remove(Func _func)
	{
		m_Container.remove_if(_func);
	}

	template<class Entity>
	template<typename Func>
	void EntityManager<Entity>::accept(Func _func)
	{
		std::for_each(m_Container.begin(), m_Container.end(), _func);
	}
}