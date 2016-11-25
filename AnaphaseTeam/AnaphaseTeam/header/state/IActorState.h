#pragma once
/**
* @file IActorState.h
* @brief �A�N�^�[�X�e�[�g�C���^�[�t�F�C�X
* @author �����T��
* @date 2016/11/26
*/
class Actor;
class IActorState
{
public:
	virtual ~IActorState() {}
	virtual void start() = 0;
	virtual void update(float _deltaTime) = 0;
	virtual void setActor(Actor* _actor) = 0;
	virtual Actor* getActor() = 0;
	/**
	* @fn
	* @brief clone�̍쐬
	*/
	virtual IActorState* clone() const = 0
};