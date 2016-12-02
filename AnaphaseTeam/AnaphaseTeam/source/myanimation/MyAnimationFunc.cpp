#include "..\..\header\myanimation\MyAnimationFunc.h"
#include "../../header/myanimation/MyAnimationContainer.h"
void startMyAnimation(unsigned int _index, Transform * _target, MYANIMATION_MODE _mode)
{
	MyAnimationContainer::getInstance().start(_index, _target,_mode);
}

void updateMyAnimation(unsigned int _index, float deltaTime)
{
	MyAnimationContainer::getInstance().update(_index, deltaTime);
}

const bool isEndMyAnimation(unsigned int _index)
{
	return MyAnimationContainer::getInstance().isEnd(_index);
}
