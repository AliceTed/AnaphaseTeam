#pragma once
#include <gslib.h>
class IEnemy;
class EnemyMediator
{
public:
	virtual float requestDistancePlayer(IEnemy* _enemy) = 0;
	virtual bool requestDistanceOtherEnemy(IEnemy * _enemy) = 0;
	virtual bool reqestGoToNear()=0;
	virtual bool reqestGoToMid()=0;
	virtual GSquaternion requestDirectionPlayer(IEnemy * _enemy)=0;
};