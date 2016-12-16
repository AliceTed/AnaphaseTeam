#pragma once
/**
* @file ActorState.h
* @brief �e���v���\�g�A�N�^�[�X�e�[�g
* @author �����T��
* @date 2016/11/26
*/
#include "IActorState.h"
#include "ACTOR_STATE.h"
#include "../device/GameDevice.h"
class Actor;
template<typename T>
class ActorState:public IActorState
{
protected:
	ActorState(T* _actor = nullptr)
		:m_actor(_actor) {}
	void setActor(Actor* _actor)
	{
		m_actor = static_cast<T*>(_actor);
	}
	Actor* getActor()
	{
		return static_cast<Actor*>(m_actor);
	}
	/**
	* @fn
	* @brief ��Ԃ̐ݒ�
	*/
	void changeState(ACTOR_STATE _name)
	{
		m_actor->changeState(_name);
	}

private:
	virtual void start()=0;
	virtual void action(float deltaTime) = 0;
	/**
	* @fn
	* @brief clone�̍쐬
	*/
	virtual ActorState* clone() const = 0;

protected:
	T* m_actor;
};