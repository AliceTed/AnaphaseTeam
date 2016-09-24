#pragma once
/**
*@file Player.h
*@drief プレイヤークラス
*@author 久秋雅
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
	* @brief アクションステートの切り替え関数
	* @param (_action) 切り替えるアクションのShared_ptr
	*/
	void actionChange(Action_Ptr _action);

	void movement(float deltaTime, float _speed = MOVESPEED);
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);

	void jumpMotion(JumpControl& _control,ANIMATION_ID _id);
	void attackmotion(Attack& _attack);
	const bool isEndAttackMotion(const Attack& _attack)const;
public://入力
	const bool isJump() const;
	const bool isGround() const;
	const bool isEndAttack() const;
	//近接用
	const bool isAttack()const;
	const bool isGunAttack()const;
	//入力方向
	const GSvector3 inputDirection()const;
public://Actor継承
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer, const Camera& _camera) override;
	void createCollision(CollisionMediator* _mediator) override;
	void othercollision(CollisionType _myType, CollisionType _otherType, Actor* _other);
private:
	void inGround() override;
public://ICharacter実装
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
	//JumpControlに移動と名前の変更(空中状態かどうかを表す変数止する)
	bool m_GroundHit;

private://定数
	static const float MOVESPEED;
	static const float ROTATESPEED;
	static const float WALKSPEED;
};