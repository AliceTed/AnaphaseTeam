/**
*@file Actor.h
*@drief �L�����̐e�N���X
*@author �a�J�m��
*@date 2016/08/11
*/
#pragma once
class Actor
{
public:
	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void finish() = 0;
protected:
	virtual void stand() = 0;
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void damage() = 0;
private:
	bool m_isDead;
};
