#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Goblin.h"
class MiddleRangeAI:public IEnemyAI
{
public:
	MiddleRangeAI(Goblin* _actor);
	~MiddleRangeAI();

	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Goblin* m_actor;
};