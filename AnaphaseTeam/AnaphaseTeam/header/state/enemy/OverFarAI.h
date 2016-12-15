#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Goblin.h"
class OverFarAI :public IEnemyAI
{
public:
	OverFarAI(Goblin* _actor);
	~OverFarAI();

	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Goblin* m_actor;
};