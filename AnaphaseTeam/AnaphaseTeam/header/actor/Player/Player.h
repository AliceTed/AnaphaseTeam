#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include "../Actor.h"
#include "../IActionState.h"
#include <memory>
#include "../ICharacter.h"
#include "../../animation/Animator.h"
#include "../../device/Input.h"
class Renderer;
typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor,public ICharacter
{
public:
	Player(const Input* _input);
	~Player();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	//void collisionGround(const Map& _map);
	void finish();
	void stand(float deltaTime);
	void move(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void jump(float deltaTime);
	/**
	* @fn
	* @brief �A�N�V�����X�e�[�g�̐؂�ւ��֐�
	* @param (_action) �؂�ւ���A�N�V������Shared_ptr
	*/
	void actionChange(Action_Ptr _action);
private:
	Action_Ptr m_action;
	Animator m_animator;
	const Input* m_Input;
	static const float MOVESPEED;
	static const float ROTATESPEED;
};