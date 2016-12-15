#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Goblin.h"
class OverNearAI :public IEnemyAI
{
public:
	OverNearAI(Goblin* _enemy);
	~OverNearAI();
	// IEnemyAI ����Čp������܂���
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Goblin* m_actor;
};