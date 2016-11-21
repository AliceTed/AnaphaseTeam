/**
 *@file LockOn.h
 *@brief ���b�N�I���N���X
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
	* @brief ��ԋ߂��G��T��
	* @detail Enemy�����݂��Ă��Ȃ��̂ŉ��ł�
	*/
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	void homing();

	//��肠�����v���C���[�������Ă�̂ł����ɏ�����
	void thinksEnemy(EnemyManager* _enemys);
private:
	//! Player��Enemy�Ƃ̋���
	float m_distance;
	//! ���߂������̊i�[�pvector
	vector<float> m_distanceStoreVector;
	Player* m_player;
	unique_ptr<Enemy>*  m_target;
	GameDevice* m_device;
};