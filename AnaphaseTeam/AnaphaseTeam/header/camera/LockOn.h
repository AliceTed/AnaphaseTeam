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

/*
Enemyの管理をシェアードポインタに変えたので
Enemyの基本的な受け渡しをシェアードポインタに変更
ターゲットをweakポインタに変更
2016/12/14 松尾
*/
class LockOn
{
public:
	LockOn();
	~LockOn();
	/**
	* @brief 一番近い敵を探す
	* @detail Enemyが存在していないので仮です
	*/
	void update(float deltaTime);
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	//取りあえずプレイヤーを持ってるのでここに書いた
	void thinksEnemy(EnemyManager* _enemys);
	std::weak_ptr<Enemy> getTarget()const;

private:
	Player* m_player;
	std::weak_ptr<Enemy>  m_target;

};