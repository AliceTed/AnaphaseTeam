#pragma once

#include "../../header/transform/Transform.h"
class Player;
class Enemy;
class Gauge;

class Homing
{
public:
	Homing();
	~Homing();
	void start(Player* _player, Enemy* _enemy, Transform& _transform, Gauge& _gauge, GSvector3 _target, bool _islockon);
	void update(float deltatime, GSvector3* _position);

private:
	bool m_isStart;
	GSvector3 m_position;
	GSvector3 m_target;
};