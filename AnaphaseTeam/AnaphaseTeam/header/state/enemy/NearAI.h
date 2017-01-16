#pragma once
#include"IEnemyAI.h"
#include "actor/Enemy/Goblin.h"
class NearAI:public IEnemyAI
{
public:
	NearAI(Goblin* _enemy);
	~NearAI();
	// IEnemyAI ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Goblin* m_actor;
};