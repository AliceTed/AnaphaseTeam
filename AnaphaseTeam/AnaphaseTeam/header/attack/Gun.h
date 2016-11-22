/**
* @file Gun.h
* @brief eUŒ‚
* @author ‹gŒ³‰ëŠì
* @date 2016/09/01
*/
#pragma once
#include "IWeapon.h"
#include "../actionstate/IActionState.h"
class Gun //: public IWeapon
{
public:
	Gun(/*MODEL_ID _model_id*/);
	~Gun();
	void initialize();
	void update();
	void animation();
private:
	float m_gunValu;
	//Animator m_animator;
};

