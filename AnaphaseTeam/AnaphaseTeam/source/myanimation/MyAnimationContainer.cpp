#include "..\..\header\myanimation\MyAnimationContainer.h"
#include "../../header/myanimation/MyAnimation.h"
MyAnimationContainer::MyAnimationContainer()
	:m_container(new AnimationPtr[128])
{
}

void MyAnimationContainer::add(unsigned int _index, MyAnimation * _animation)
{
	m_container[_index]=AnimationPtr(_animation);
}

void MyAnimationContainer::start(unsigned int _index, Transform * _target, MYANIMATION_MODE _mode)
{
	if (LENGHT <= _index)return;
	m_container[_index]->start(_target, _mode);
}

void MyAnimationContainer::update(unsigned int _index, float deltaTime)
{
	if (LENGHT <= _index)return;
	m_container[_index]->update(deltaTime);
}

const bool MyAnimationContainer::isEnd(unsigned int _index) const
{
	if (LENGHT <= _index)return true;
	return m_container[_index]->isEnd();
}