#pragma once
/**
@file	EnemyRatateTimer.h
@brief	エネミーの旋回に使用する補間のタイマークラス
@author Hiaaki
@date	2016/12/16
*/
struct LerpTimer
{
public:
	void begin()
	{
		time = 0.0f;
		maxTime = 10.0f;
	}
	void update(float deltatime)
	{
		time += time < maxTime ? deltatime * 1 : 0;
	}
public:
	float time = 0;
	float maxTime = 10.0f;
};