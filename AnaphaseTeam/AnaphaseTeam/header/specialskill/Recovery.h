#pragma once
#include "ISpecialSkill.h"
#include "../convenient/Timer.h"
class Recovery :public ISpecialSkill
{
public:
	Recovery();
	void start() override;
	void update(float deltaTime) override;
	const bool isEnd() const override;
	const float consumption() const override;
private:
	Timer m_limit;
};