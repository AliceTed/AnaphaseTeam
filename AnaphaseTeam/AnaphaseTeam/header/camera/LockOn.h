/**
 *@file LockOn.h
 *@brief ロックオンクラス
 *@author Ruri
 *@date 2016.9.1
 */

#pragma once

#include <vector>
#include <algorithm>
using namespace std;

class CameraController;
class EnemyManager;
class Enemy;
class Player;

class LockOn
{
public:
	LockOn();
	~LockOn();
	/**
	* @brief 一番近い敵を探す
	* @detail Enemyが存在していないので仮です
	*/
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	void homing();

private:
	//! PlayerとEnemyとの距離
	float m_distance;
	//! 求めた距離の格納用vector
	vector<float> m_distanceStoreVector;
	Player* m_player;
	Enemy* m_target;

};