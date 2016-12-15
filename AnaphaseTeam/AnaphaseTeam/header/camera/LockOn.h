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

/*
Enemy�̊Ǘ����V�F�A�[�h�|�C���^�ɕς����̂�
Enemy�̊�{�I�Ȏ󂯓n�����V�F�A�[�h�|�C���^�ɕύX
�^�[�Q�b�g��weak�|�C���^�ɕύX
2016/12/14 ����
*/
class LockOn
{
public:
	LockOn();
	~LockOn();
	/**
	* @brief ��ԋ߂��G��T��
	* @detail Enemy�����݂��Ă��Ȃ��̂ŉ��ł�
	*/
	void update(float deltaTime);
	void nearEnemyFind(EnemyManager* _enemys);
	void addPlayer(Player* _player);
	void look_at(CameraController* _camera);
	//��肠�����v���C���[�������Ă�̂ł����ɏ�����
	void thinksEnemy(EnemyManager* _enemys);
	std::weak_ptr<Enemy> getTarget()const;

private:
	Player* m_player;
	std::weak_ptr<Enemy>  m_target;

};