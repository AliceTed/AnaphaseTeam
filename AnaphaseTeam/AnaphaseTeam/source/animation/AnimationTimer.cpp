#include "AnimationTimer.h"

AnimationTimer::AnimationTimer(float _timer, float speed)
	:timer(0), defTimer(_timer), speed(speed), isStart(true)
{
}

AnimationTimer::~AnimationTimer()
{
}
void AnimationTimer::initialize()
{
	timer = 0;
	isStart = true;
}
void AnimationTimer::update(float deltaTime)
{
	if (getIsStop())
	{
		return;
	}
	if (getIsEnd())
	{
		return;
	}
	timer += 1.0f*speed*deltaTime;
}

void AnimationTimer::stop()
{
	isStart = false;
}
void AnimationTimer::start()
{
	isStart = true;
}
const bool AnimationTimer::getIsStop()const
{
	return !isStart;
}

const float AnimationTimer::getTime()const
{
	return timer;
}
const bool AnimationTimer::getIsEnd()const
{
	return timer >= defTimer;
}