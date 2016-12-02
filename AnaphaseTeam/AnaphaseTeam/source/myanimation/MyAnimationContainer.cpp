#include "..\..\header\myanimation\MyAnimationContainer.h"
#include "../../header/myanimation/MyAnimation.h"
MyAnimationContainer::MyAnimationContainer()
	:m_container()
{
}

void MyAnimationContainer::add(MyAnimation * _animation)
{
	m_container.emplace_back(AnimationPtr(_animation));
}

void MyAnimationContainer::start(unsigned int _index, Transform * _target, MYANIMATION_MODE _mode)
{
	if (size() <= _index)return;
	m_container.at(_index)->start(_target, _mode);
}

void MyAnimationContainer::update(unsigned int _index, float deltaTime)
{
	if (size() <= _index)return;
	m_container.at(_index)->update(deltaTime);
}

const bool MyAnimationContainer::isEnd(unsigned int _index) const
{
	if (size() <= _index)return true;
	return m_container.at(_index)->isEnd();
}

const unsigned int MyAnimationContainer::size() const
{
	return m_container.size();
}
