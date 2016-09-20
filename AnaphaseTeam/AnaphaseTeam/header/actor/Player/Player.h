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
#include "../../subAction/TestChainMove.h"
#include "../../convenient/Timer.h"
#include<gslib.h>
#include <memory>
#include "../Actor.h"
#include "../ICharacter.h"

//#include "../../subAction/SubActionManager.h"
#include "../../../header/subAction/SubActionManager.h"
#include "../../airstate/JumpControl.h"

class Input;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor, public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	void chain(float deltaTime);
	void chainMove(const GSvector3 & _target, float _time);

	/**
	* @fn
	* @brief アクションステートの切り替え関数
	* @param (_action) 切り替えるアクションのShared_ptr
	*/
	void actionChange(Action_Ptr _action);
	void movement(float deltaTime, float _speed = MOVESPEED);
	void subActionStart();
	void jumping(float _velocity);
	void jumpUp();
	void jumpRigor();
	
public://Actor継承
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer, const Camera& _camera) override;
	void collisionGround(const Map& _map) override;
	void createCollision(CollisionMediator* _mediator) override;

public://ICharacter実装
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void jump(float deltaTime);
	void walk(float deltaTime);
private:
	void control();
private:
	const Input* m_Input;
	TestChainMove m_ChainMove;
	Action_Ptr m_action;
	subActionManager m_SubAction;
private://定数
	static const float MOVESPEED;
	static const float ROTATESPEED;
	static const float WALKSPEED;
};