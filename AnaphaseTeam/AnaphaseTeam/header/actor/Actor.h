/**
*@file Actor.h
*@drief �L�����̐e�N���X
*@author �a�J�m��
*@date 2016/08/11
*/
#pragma once
#include "../convenient/Transform.h"
#include "../data/Model_ID.h"

#include "../data/ANIMATION_ID.h"
#include "../data/SKELETON_ID.h"
#include "../animation/Animator.h"
#include "../animation/AnimatorOne.h"
#include "../shape/Sphere.h"
#include "../actor/Actor_Tag.h"

class Renderer;
class CollisionMediator;
class Map;
class Camera;
class CollisionTable;

class Player;
class TestActor;
//!�@�����̃t���O��false�Ȃ烊�^�[��
#define FALSE_RETURN(flg) if(!flg)return;
class Actor
{
public:
	Actor(const Transform &_transform,const MODEL_ID _model_ID,const Sphere& _sphere, Actor_Tag _tag);
	Actor(const Transform &_transform, const ANIMATION_ID _anim_ID,const SKELETON_ID _skelton_ID, const Sphere& _sphere, Actor_Tag _tag);

	virtual ~Actor() {}
	virtual void initialize();
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer& _renderer,const Camera& _camera) = 0;
	virtual void finish();

	/**
	* @fn
	* @brief Map�Ƃ̏Փˊ֐�
	* @param (_map) map���擾
	*/
	virtual void collisionGround(const Map& _map);
	/**
	* @fn
	* @brief ���g���쐬��������p�I�u�W�F�N�g���Փ˂�����Ă΂��
	* @param (_other)�Փ˂���actor�N���X���擾
	*/
	virtual void collision(Actor* _other);
	/**
	* @fn
	* @brief �֐����Ŕ���p�I�u�W�F�N�g�𐶐��o����
	* @param (_mediator)����p�I�u�W�F�N�g���i�[�ł��� 
	*/
	virtual void createCollision(CollisionMediator* _mediator);

	/**
	* @fn
	* @brief �n�ʂɖ��ߍ��܂ꂽ�Ƃ��ɌĂ΂��
	*/
	virtual void inGround();
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

	const bool isSameActor(const Actor* _other)const;
	const bool isSameTag(Actor_Tag _tag)const;
	/**
	* @fn
	* @brief ����\����Փ˔�����s��actor�����f����
	* @param (_table) ����\
	* @param (_other) �m�F����actor
	*/
	const bool isConfirmCollisionTable(const CollisionTable& _table, const Actor* _other)const;
public:
	const bool isDead()const;
	
protected:
	/**
	* @fn
	* @brief �J�����Ƃ̋������烿�l�𒲐�
	* @param (_camera) �J�������擾
	*/
	void alphaBlend(const Camera& _camera);
	/**
	* @fn
	* @brief �J�����ɉf���Ă��邩����
	* @param (_camera) �J�������擾
	* @return �J�����ɉf���Ă��邩�H
	*/
	const bool isInsideView(const Camera& _camera)const;
	/**
	* @fn
	* @brief �J�����p����Actor�ɒǏ]������
	* @param (_offset)����
	*/
	void sphereChases(const GSvector3 &_offset=GSvector3(0,0,0));

	/**
	* @fn
	* @brief �J�����p����`��(debug�p)
	* @param (_renderer)�`��@�\�N���X
	*/
	void sphereDraw(const Renderer& _renderer);
protected:
	Transform m_transform;
	bool m_isDead;

	GScolor m_Color;
	//Animator m_animator;
	AnimatorOne m_animatorOne;
private:
	Actor_Tag m_Tag;

	//!�J�����p����
	Sphere m_Sphere;
	//!���u�����h���n�߂鋗��
	static const float ALPHABLEND_FAR;
};
