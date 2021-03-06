#pragma once
#include"IEnemyAI.h"
#include "actor/Enemy/Goblin.h"
class OverNearAI :public IEnemyAI
{
public:
	OverNearAI(Goblin* _enemy);
	~OverNearAI();
	// IEnemyAI を介して継承されました
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Goblin* m_actor;
};