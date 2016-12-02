#pragma once
#include "ISpecialSkill.h"
class Player;
class SpecialAttack :public ISpecialSkill
{
public:
	SpecialAttack(Player* _player);
	void start() override;
	void update(float) override;
	const bool isEnd() const override;
	const float consumption() const override;
private:
	Player* m_player;
};
