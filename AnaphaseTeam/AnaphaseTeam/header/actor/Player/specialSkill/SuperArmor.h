#pragma once

#include "../../../../header/convenient/Timer.h"

class Gauge;
class Status;

class SuperArmor
{
public:
	SuperArmor();
	~SuperArmor();
	void initialize(Gauge* _gauge);
	void update(float deltaTime);
	const bool isEnd() const;
	const bool isSuperArmor();

private:
	Timer m_limitTimer;
	bool m_isSuperArmor;
};