/**
 *@file LockOn.h
 *@brief ���b�N�I���N���X
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
	* @brief ��ԋ߂��G��T��
	* @detail Enemy�����݂��Ă��Ȃ��̂ŉ��ł�
	*/
	void nearEnemyFind();
	void addPlayer();
	void addEnemy();

private:
	//! Player��Enemy�Ƃ̋���
	float m_distance;
	//! ���߂������̊i�[�pvector
	vector<float> m_distanceStoreVector;
	Player* m_player;
	vector<Boss*> m_Enemys;
};