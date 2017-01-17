#pragma once
#include "Thread.h"
#include "CriticalSection.h"
class LoadThread : public Thread
{
public:
	LoadThread();
	~LoadThread();
	void run();
	void end();
	const bool isEnd()const;
private:
	void loadTextrue();
	void loadSound();
	void loadModel();
	void loadMyAnimation();
private:
	CriticalSection m_section;
	bool m_isEnd;
};