#pragma once
#include"state\enemy\IEnemyAI.h"
#include "Boss.h"
class BossAI :public IEnemyAI
{
public:
	BossAI(Boss* _enemy);
	~BossAI();
	// IEnemyAI を介して継承されました
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Boss* m_actor;
};