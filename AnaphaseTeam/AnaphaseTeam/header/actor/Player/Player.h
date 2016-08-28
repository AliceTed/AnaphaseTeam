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
#include "../../animation/AnimationTimer.h"
#include "../../actor/state/IActionState.h"
#include "../TestChainMove.h"
#include "../../convenient/Timer.h"
#include<gslib.h>
#include <memory>
#include "../ICharacter.h"
#include "../airstate/jumpControl.h"
#include "../../subAction/subActionManager.h"
class Input;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor,public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void collisionGround(const Map& _map);
	void finish();
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void chain(float deltaTime);
	void jumping(float _velocity);
	void chainMove(const GSvector3 & _target, float _time);
	void subActionStart(jumpControl* _jump, TestChainMove* _chainMove);
	
	
private:
	void control();
	/**
	* @fn
	* @brief �A�N�V�����X�e�[�g�̐؂�ւ��֐�
	* @param (_action) �؂�ւ���A�N�V������Shared_ptr
	*/
	void actionChange(Action_Ptr _action);
private:
	const Input* m_Input;
	Animator m_animator;

	TestChainMove m_ChainMove;

	static const float MOVESPEED;
	static const float ROTATESPEED;
	Action_Ptr m_action;
	subActionManager m_SubAction;
};