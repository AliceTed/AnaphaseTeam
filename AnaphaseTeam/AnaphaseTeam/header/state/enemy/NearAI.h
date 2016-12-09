#pragma once
#include"IEnemyAI.h"
#include "../../../header/actor/Enemy/Enemy.h"
class NearAI:public IEnemyAI
{
public:
	NearAI(Enemy* _enemy);
	~NearAI();
	// IEnemyAI ����Čp������܂���
	virtual void initialize() override;
	virtual void think(Player * _player) override;
private:
	Enemy* m_actor;
};