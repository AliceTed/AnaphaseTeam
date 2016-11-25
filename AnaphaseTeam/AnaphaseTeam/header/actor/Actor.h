/**
*@file Actor.h
*@drief �L�����̐e�N���X
*@author �a�J�m��
*@date 2016/08/11
*/
#pragma once
#include <unordered_map>
#include <memory>
#include "../../header/transform/Transform.h"
#include "../data/Model_ID.h"
#include "../animation/AnimatorOne.h"
#include "../actor/Actor_Tag.h"
#include "../collision/CollisionGroup.h"
#include "../state/ACTOR_STATE.h"
class Renderer;
class Map;
class IActorState;
class Actor
{
public:
	Actor(const Transform &_transform,const MODEL_ID _model_ID, Actor_Tag _tag);
	virtual ~Actor();
	virtual void initialize();
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer& _renderer) = 0;
	virtual void finish();
	/**
	* @fn
	* @brief Map�Ƃ̏Փˊ֐�
	* @param (_map) map���擾
	*/
	virtual void collisionGround(const Map& _map);
private:
	/**
	* @fn
	* @brief �n�ʂɖ��ߍ��܂ꂽ�Ƃ��ɌĂ΂��
	*/
	virtual void inGround();
public:
	//���݂̏�Ԃ�Ԃ�
	const ACTOR_STATE getState() const;
	void collision(Actor& _other);
	const bool isDead()const;
	const bool isSameActor(const Actor* _other)const;
	const bool isSameTag(Actor_Tag _tag)const;
protected:
	void changeState(ACTOR_STATE _state);
	//�ϐ���protected�Ɏg�p���Y��ł���
	void state_update(float deltaTime);
	void registerState(ACTOR_STATE _name, IActorState* _state);
public:
	/**
	* @fn
	* @brief Actor���m�̋���
	* @param (_ohter) �����𑪂�Actor
	* @return ����
	*/
	const float distanceActor(const Actor& _other)const;
	//chain�v�Z�p�ɂ��邾��distanceActor��ɂ�����
	const float distance(const GSvector3& _position)const;
	//_target�̕��������߂�
	const GSquaternion targetDirection(const Actor& _target)const;
private:
	//�R�s�[�֎~
	Actor(const Actor&);
	Actor& operator=(const Actor&);

protected:
	Transform m_transform;
	bool m_isDead;
	AnimatorOne m_animatorOne;
	CollisionGroup m_collision;
private:
	using StatePtr = std::shared_ptr<IActorState>;
	using StateContainer = std::unordered_map< ACTOR_STATE, StatePtr>;
	StateContainer m_states;
	StatePtr m_currentState;
	ACTOR_STATE m_currentStateKey;

	Actor_Tag m_Tag;
	//�d��
	static const float GRAVITY;
};
