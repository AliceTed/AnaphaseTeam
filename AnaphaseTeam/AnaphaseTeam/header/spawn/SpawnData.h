/**
* @file SpawnData.h
* @brief ¶¬—p\‘¢‘Ì
* @author ¼”ö—T–ç
* @date 2016/12/14
*/
#pragma once
#include "SpawnArea.h"
#include "../actor/Enemy/ENEMY_TYPE.h"
struct SpawnData
{
	unsigned int activeNumber;
	SpawnArea area;
	ENEMY_TYPE type;
	unsigned int spawnNum;
};