#pragma once
#include <gslib.h>
class IEnemy;
#include "state\enemy\EAI.h"
class EnemyMediator
{
public:
	virtual float requestDistancePlayer(IEnemy* _enemy) = 0;
	virtual bool requestDistanceOtherEnemy(IEnemy * _enemy) = 0;
	virtual bool isExist(EAI _range) = 0;
	virtual bool reqestGoToNear() = 0;
	virtual bool reqestGoToMid() = 0;
	virtual GSquaternion requestPlayerDirection(IEnemy * _enemy) = 0;
	virtual void addScore(int _score) = 0;
};