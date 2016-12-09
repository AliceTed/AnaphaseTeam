#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Enemy.h"
class OverNearAI :public IEnemyAI
{
public:
	OverNearAI(Enemy* _enemy);
	~OverNearAI();
	// IEnemyAI ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Enemy* m_actor;
};