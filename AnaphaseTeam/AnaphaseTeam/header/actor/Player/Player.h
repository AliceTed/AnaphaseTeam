#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include "../Actor.h"
#include "../../animation/Animation.h"
#include "../../animation/Animator.h"
#include "../../actionstate/IActionState.h"
#include "../../convenient/Timer.h"
#include<gslib.h>
#include <memory>
#include "../Actor.h"
#include "../ICharacter.h"

#include "../../../header/subAction/SubActionManager.h"

#include "../../attack/Scythe.h"
#include "../../attack/Gun.h"
#include "../../attack/attackManager.h"
#include "../../data/ANIMATION_ID.h"

class Input;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor, public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	/**
	* @fn
	* @brief �A�N�V�����X�e�[�g�̐؂�ւ��֐�
	* @param (_action) �؂�ւ���A�N�V������Shared_ptr
	*/
	void actionChange(Action_Ptr _action);

	void movement(float deltaTime, float _speed = MOVESPEED);
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);

	void jumpMotion(JumpControl& _control,ANIMATION_ID _id);
	void attackmotion(Attack& _attack);
	const bool isEndAttackMotion(const Attack& _attack)const;
public://����
	const bool isJump() const;
	const bool isGround() const;
	const bool isEndAttack() const;
	//�ߐڗp
	const bool isAttack()const;
	const bool isGunAttack()const;
	//���͕���
	const GSvector3 inputDirection()const;
public://Actor�p��
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer, const Camera& _camera) override;
	void createCollision(CollisionMediator* _mediator) override;
	void othercollision(CollisionType _myType, CollisionType _otherType, Actor* _other);
private:
	void inGround() override;
public://ICharacter����
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void jump(float deltaTime);
	void walk(float deltaTime);
	void avoid(float deltaTime);
private:
	void control();
	void subActionStart();
	void moveMotionChange();
private:
	const Input* m_Input;
	Action_Ptr m_action;
	subActionManager m_SubAction;
	AttackManager m_attackManager;
	//JumpControl�Ɉړ��Ɩ��O�̕ύX(�󒆏�Ԃ��ǂ�����\���ϐ��~����)
	bool m_GroundHit;

private://�萔
	static const float MOVESPEED;
	static const float ROTATESPEED;
	static const float WALKSPEED;
};