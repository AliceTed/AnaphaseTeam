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
#include "../../animation/AnimationTimer.h"
#include "../../actionstate/IActionState.h"
#include "../../subAction/TestChainMove.h"
#include "../../convenient/Timer.h"
#include<gslib.h>
#include <memory>
#include "../Actor.h"
#include "../ICharacter.h"

#include "../../subAction/TestJump.h"
#include "../../subAction/subActionManager.h"
#include "../airstate/jumpControl.h"

class Input;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor, public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	void subActionStart(TestJump* _jump, TestChainMove* _chainMove);
	/**
	* @fn
	* @brief アクションステートの切り替え関数
	* @param (_action) 切り替えるアクションのShared_ptr
	*/
	void actionChange(Action_Ptr _action);
	
public://Actor継承　見にくいから分けろ
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void collisionGround(const Map& _map);
	void createCollision(CollisionMediator* _mediator);

public://ICharacter実装
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void jump(float deltaTime);
	void chain(float deltaTime);
	void jumping(float _velocity);
	void chainMove(const GSvector3 & _target, float _time);
	void subActionStart(jumpControl* _jump, TestChainMove* _chainMove);

	void subActionStart();
	
	
private:
	void control();
private:
	const Input* m_Input;

	TestChainMove m_ChainMove;

	static const float MOVESPEED;
	static const float ROTATESPEED;
	Action_Ptr m_action;
	subActionManager m_SubAction;
};