#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Enemy.h"
class MiddleRangeAI:public IEnemyAI
{
public:
	MiddleRangeAI(Enemy* _actor);
	~MiddleRangeAI();

	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Enemy* m_actor;
};