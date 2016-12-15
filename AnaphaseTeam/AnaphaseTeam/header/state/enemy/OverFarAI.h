#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Enemy.h"
class OverFarAI :public IEnemyAI
{
public:
	OverFarAI(Enemy* _actor);
	~OverFarAI();

	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Enemy* m_actor;
};