/**
* @file Scythe.h
* @brief äôçUåÇ
* @author ãgå≥âÎäÏ
* @date 2016/09/01
*/
#pragma once
#include "IWeapon.h"
#include "../animation/Animator.h"
#include "../actionstate/IActionState.h"
//typedef std::shared_ptr<IActionState> Action_Ptr;
class Scythe //: public IWeapon
{
public:
	Scythe(/*MODEL_ID _model_id*/);
	~Scythe();
	void initialize();
	void update();
	void animation();
private:
	float m_scytheValu;
	//Animator m_animator;
};