#pragma once
#ifndef _ANIMATIONTIMER_H_
#define _ANIMATIONTIMER_H_

/*
AnimationTimer

0から任意の数値に増えていく
speedで速さ指定
*/
class AnimationTimer
{
public:
	AnimationTimer(float _timer,float speed=1.0f);
	~AnimationTimer();
	void initialize();
	void update(float deltaTime);

	void stop();
	void start();
	const bool getIsStop()const;
	const float getTime()const;
	const float getEndTime()const;
	const bool getIsEnd()const;

	const float getSpeed() const;

private:
	float timer;
	float defTimer;
	float speed;
	bool isStart;
};

#endif