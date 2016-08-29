#pragma once
#include <gslib.h>
#include "../convenient/Timer.h"
class Player;
class TestChainMove
{
public:
	TestChainMove();
	~TestChainMove();

	void start();
	void movement(float deltaTime,Player* _player);

	void fling();
private:
	bool m_isChainMove;
	GSvector3 m_Target;
	Timer m_Timer;

	static const float MOVESPEED;
};