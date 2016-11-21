/**
 *@file LockOn.h
 *@brief ロックオンクラス
 *@author Ruri
 *@date 2016.9.1
 */

#pragma once

#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class CameraController;
class EnemyManager;
class Enemy;
class Player;
class GameDevice;

class LockOn
{
public:
	LockOn(GameDevice* _device);
	~LockOn();
	/**
	* @brief 一番近い敵を探す
	* @detail Enemyが存在していないので仮です
	*/
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	void homing();

	//取りあえずプレイヤーを持ってるのでここに書いた
	void thinksEnemy(EnemyManager* _enemys);
private:
	//! PlayerとEnemyとの距離
	float m_distance;
	//! 求めた距離の格納用vector
	vector<float> m_distanceStoreVector;
	Player* m_player;
	unique_ptr<Enemy>*  m_target;
	GameDevice* m_device;
};