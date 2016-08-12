#pragma once
/**
*@file Player.h
*@drief プレイヤークラス
*@author 久秋雅
*@date 2016/08/12
*/
#include "Actor.h"
class Player :public Actor
{
public:
	Player();
	~Player();
	void initialize();
	void update();
	void draw();
	void finish();
	void stand();
	void move();
	void attack();
	void damage();
private:

};