#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Enemy.h"
class OverNearAI :public IEnemyAI
{
public:
	OverNearAI(Enemy* _enemy);
	~OverNearAI();
	// IEnemyAI を介して継承されました
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Enemy* m_actor;
};