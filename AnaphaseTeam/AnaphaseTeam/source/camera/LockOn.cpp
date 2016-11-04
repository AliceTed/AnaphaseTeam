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
	//本来の引数はEnemy
	//m_distance = player.distanceActor(player);
	m_distanceStoreVector.emplace_back(m_distance);
	//最小値の要素番号を取得
	vector<float>::iterator itr = min_element(m_distanceStoreVector.begin(), m_distanceStoreVector.end());
	int index = distance(m_distanceStoreVector.begin(), itr);
	
	//この後、取得した番号のEnemyを返す
}

void LockOn::addPlayer()
{
}

void LockOn::addEnemy()
{
}
