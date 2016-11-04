/**
 *@file LockOn.h
 *@brief ロックオンクラス
 *@author Ruri
 *@date 2016.9.1
 */

#pragma once

#include <vector>
#include <algorithm>
#include "../../header/actor/Boss/Boss.h"
#include "../../header/actor/Player/Player.h"
using namespace std;

class LockOn
{
public:
	LockOn();
	~LockOn();
	/**
	* @brief 一番近い敵を探す
	* @detail Enemyが存在していないので仮です
	*/
	void nearEnemyFind();
	void addPlayer();
	void addEnemy();

private:
	//! PlayerとEnemyとの距離
	float m_distance;
	//! 求めた距離の格納用vector
	vector<float> m_distanceStoreVector;
	Player* m_player;
	vector<Boss*> m_Enemys;
};