/**
*@file Actor.h
*@drief �L�����̐e�N���X
*@author �a�J�m��
*@date 2016/08/11
*/
#pragma once
#include "../Transform.h"
class Actor
{
public:
	Actor(const Transform &_transform):m_transform(_transform),m_isDead(false){}
	virtual ~Actor() {}
	virtual void initialize() { m_isDead = false; };
	virtual void update(float deltatime) = 0;
	virtual void draw() = 0;
	virtual void finish() {}

protected:
	Transform m_transform;
	bool m_isDead;
};
