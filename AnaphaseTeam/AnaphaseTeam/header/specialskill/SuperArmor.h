#pragma once
#include "ISpecialSkill.h"
#include "../convenient/Timer.h"
class SuperArmor :public ISpecialSkill
{
public:
	SuperArmor();
	void start() override;
	void update(float deltaTime) override;
	const bool isEnd() const override;
	const float consumption() const override;
private:
	Timer m_limit;
};