/**
*@file Actor.h
*@drief �L�����̐e�N���X
*@author �a�J�m��
*@date 2016/08/11
*/
#pragma once
#include "../Transform.h"
#include "../shape/Sphere.h"
#include "../actor/Actor_Tag.h"
class CollisionMediator;
class Map;
class Renderer;
class Camera;
//!�@�����̃t���O��false�Ȃ烊�^�[��
#define FALSE_RETURN(flg) if(!flg)return;
class Actor
{
public:
	Actor(const Transform &_transform,const Sphere& _sphere,Actor_Tag _tag);
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
	virtual void collision(const Actor* _other);

	virtual void createCollision(CollisionMediator* _mediator);

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

	Actor_Tag m_Tag;
private:

	//!�J�����p����
	Sphere m_Sphere;
	//!���u�����h���n�߂鋗��
	static const float ALPHABLEND_FAR;
};
