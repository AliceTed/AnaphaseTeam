#pragma once
#include"state\enemy\IEnemyAI.h"
#include "Boss.h"
class BossAI :public IEnemyAI
{
public:
	BossAI(Boss* _enemy);
	~BossAI();
	// IEnemyAI ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Boss* m_actor;
};