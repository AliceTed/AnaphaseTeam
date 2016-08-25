#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include<gslib.h>
#include <memory>
#include "../Actor.h"
#include "../ICharacter.h"

#include "../../actionstate/IActionState.h"
#include "../../subAction/TestJump.h"
#include "../../subAction/TestChainMove.h"
class Input;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor, public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	void chain(float deltaTime);
	void jumping(float _velocity);
	void chainMove(const GSvector3 & _target, float _time);
	/**
	* @fn
	* @brief �A�N�V�����X�e�[�g�̐؂�ւ��֐�
	* @param (_action) �؂�ւ���A�N�V������Shared_ptr
	*/
	void actionChange(Action_Ptr _action);
	
public://Actor�p���@���ɂ������番����
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void collisionGround(const Map& _map);
	void createCollision(CollisionMediator* _mediator);

public://ICharacter����
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void jump(float deltaTime);
private:
	void control();
private:
	const Input* m_Input;

	TestJump m_Jump;
	TestChainMove m_ChainMove;

	static const float MOVESPEED;
	static const float ROTATESPEED;
	Action_Ptr m_action;
};