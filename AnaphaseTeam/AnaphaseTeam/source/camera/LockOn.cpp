#include "../../header/camera/LockOn.h"

LockOn::LockOn()
	:m_player(nullptr)
{
}

LockOn::~LockOn()
{
}

void LockOn::nearEnemyFind()
{
	if (m_player == nullptr)
	{
		return;
	}
	//�{���̈�����Enemy
	//m_distance = player.distanceActor(player);
	m_distanceStoreVector.emplace_back(m_distance);
	//�ŏ��l�̗v�f�ԍ����擾
	vector<float>::iterator itr = min_element(m_distanceStoreVector.begin(), m_distanceStoreVector.end());
	int index = distance(m_distanceStoreVector.begin(), itr);
	
	//���̌�A�擾�����ԍ���Enemy��Ԃ�
}

void LockOn::addPlayer()
{
}

void LockOn::addEnemy()
{
}
