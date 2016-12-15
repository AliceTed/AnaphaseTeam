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
class IEnemy;
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
	//取りあえずプレイヤーを持ってるのでここに書いた
	void thinksEnemy(EnemyManager* _enemys);
	IEnemy* getTarget()const;

private:
	Player* m_player;
	unique_ptr<IEnemy>*  m_target;

};