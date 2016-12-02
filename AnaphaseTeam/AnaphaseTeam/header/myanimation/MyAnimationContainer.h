#pragma once

#include <memory>
#include <vector>
#include "MYANIMATION_MODE.h"
#include "MyAnimation.h"
struct Transform;
class MyAnimationContainer
{
public:
	static MyAnimationContainer& getInstance()
	{
		static MyAnimationContainer self;
		return self;
	}
	void add(MyAnimation* _animation);
	void start(unsigned int _index,Transform* _target, MYANIMATION_MODE _mode = MYANIMATION_MODE::DEDAULT);
	void update(unsigned int _index,float deltaTime);
	const bool isEnd(unsigned int _index)const;
	const unsigned int size()const;
private:
	MyAnimationContainer();
	MyAnimationContainer(const MyAnimationContainer&);
	MyAnimationContainer& operator =(const MyAnimationContainer&);
private:
	using AnimationPtr = std::unique_ptr<MyAnimation>;
	using Container = std::vector<AnimationPtr>;
	Container m_container;
};