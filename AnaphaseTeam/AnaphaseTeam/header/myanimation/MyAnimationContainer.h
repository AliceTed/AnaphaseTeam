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
	void add(unsigned int _index,MyAnimation* _animation);
	void start(unsigned int _index,Transform* _target, MYANIMATION_MODE _mode = MYANIMATION_MODE::DEDAULT);
	void update(unsigned int _index,float deltaTime);
	const bool isEnd(unsigned int _index)const;
private:
	MyAnimationContainer();
	MyAnimationContainer(const MyAnimationContainer&);
	MyAnimationContainer& operator =(const MyAnimationContainer&);
private:
	static const int LENGHT = 128;
	using AnimationPtr = std::unique_ptr<MyAnimation>;
	using Container = std::unique_ptr<AnimationPtr[]>;
	Container m_container;
};