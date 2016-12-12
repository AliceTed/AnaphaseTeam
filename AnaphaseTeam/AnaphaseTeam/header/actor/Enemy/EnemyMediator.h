#pragma once
class Enemy;
class EnemyMediator
{
public:
	virtual float requestDistancePlayer(Enemy* _enemy) = 0;
	virtual bool requestDistanceOtherEnemy(Enemy * _enemy) = 0;
	virtual bool reqestGoToNear()=0;
	virtual bool reqestGoToMid()=0;
};