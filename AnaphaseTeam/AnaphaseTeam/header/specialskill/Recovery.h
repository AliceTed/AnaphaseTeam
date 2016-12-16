#pragma once
#include "ISpecialSkill.h"
#include "../convenient/Timer.h"
class Player;
class Recovery :public ISpecialSkill
{
public:
	Recovery(Player* _player);
	void start() override;
	void update(float deltaTime) override;
	const bool isEnd() const override;
	const float consumption() const override;
private:
	Timer m_limit;
	Player* m_player;
};