/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
#include "../Transform.h"
#include "../data/Model_ID.h"
#include "../animation/Animator.h"
class Renderer;
class Actor
{
public:
	Actor(const Transform &_transform,const MODEL_ID _model_ID):m_transform(_transform),m_isDead(false),m_animator(_model_ID){}
	virtual ~Actor() {}
	virtual void initialize() { m_isDead = false; };
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer& _renderer) = 0;
	virtual void finish() {}

protected:
	Transform m_transform;
	bool m_isDead;
	Animator m_animator;
};
