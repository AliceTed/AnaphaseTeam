#pragma once

#include "../../../../header/convenient/Timer.h"

class Gauge;
class Status;

class Recovery
{
public:
	Recovery();
	~Recovery();
	void initialize(Gauge* _gauge);
	void update(float deltaTime);
	void add(Status& _status);
	const bool isEnd() const;

private:
	Timer m_limitTimer;
	//Gauge* m_gauge;

};