/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
class Renderer;
class Actor
{
public:
	virtual ~Actor() {}
	virtual void initialize() = 0;
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer &_renderer) = 0;
	virtual void finish() = 0;
	virtual void stand() = 0;
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void damage() = 0;
private:
	bool m_isDead;
};
