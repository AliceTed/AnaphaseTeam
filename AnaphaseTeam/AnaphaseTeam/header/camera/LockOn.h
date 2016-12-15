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
class IEnemy;
class Player;

class LockOn
{
public:
	LockOn();
	~LockOn();
	/**
	* @brief ��ԋ߂��G��T��
	* @detail Enemy�����݂��Ă��Ȃ��̂ŉ��ł�
	*/
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	//��肠�����v���C���[�������Ă�̂ł����ɏ�����
	void thinksEnemy(EnemyManager* _enemys);
	IEnemy* getTarget()const;

private:
	Player* m_player;
	unique_ptr<IEnemy>*  m_target;

};