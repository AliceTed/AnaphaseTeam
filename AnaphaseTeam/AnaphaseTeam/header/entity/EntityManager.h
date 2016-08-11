#pragma once
#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_
/**
* @file EntityManager.h
* @brief �ėp�e���v���[�g�}�l�[�W���N���X
* @author �����T��
* @date 2016/8/02
*/
//�X�}�[�g�|�C���^���i�[�����Ƃ�O��ɂ��Ă���
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
		* @brief �v�f��ǉ�
		* @param (_entity)�ǉ�����v�f
		*/
		void add(const Entity& _entity);

		/**
		* @fn
		* @brief �����𖞂����v�f���폜
		* @param (_func)�����֐�
		*/
		template<typename Func>void remove(Func _func);
		/**
		* @fn
		* @brief �e�v�f�ɃA�N�Z�X����
		* @param (_func)�A�N�Z�X���e
		*/
		template<typename Func>void accept(Func _func);
		/**
		* @fn
		* @brief �v�f��
		*/
		const unsigned int size()const;
		/**
		* @fn
		* @brief �S�Ă̗v�f���폜
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