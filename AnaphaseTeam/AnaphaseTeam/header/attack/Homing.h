#pragma once
#include "../../header/math/Calculate.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/actor/Enemy/Enemy.h"

class Homing
{
public:
	Homing();
	~Homing();
	void initialize();
	void update(float deltatime);
	void distancecalc(Enemy * _enemy);
private:

};