#include "../../header/camera/LockOn.h"

LockOn::LockOn()
	:m_player(nullptr),
	m_target(nullptr)
{
}

LockOn::~LockOn()
{
}

void LockOn::nearEnemyFind(vector<Boss>& _enemys)
{
	if (m_player == nullptr)
	{
		return;
	}
	vector<float> m_distanceStoreVector;
	m_distanceStoreVector.emplace_back(m_player->distanceActor(_enemys[0]));

	//�{���̈�����Enemy
	/*m_distance = m_player->distanceActor(*m_player);
	m_distanceStoreVector.emplace_back(m_distance);*/
	/*sort(_enemys.begin(), _enemys.end(),
		[&](Boss& x, Boss& y) -> int {
		return (x.distanceActor(*m_player) < y.distanceActor(*m_player));
	});*/
	
	//m_target = &(*_enemys.begin());
	//�ŏ��l�̗v�f�ԍ����擾
	vector<float>::iterator itr = min_element(m_distanceStoreVector.begin(), m_distanceStoreVector.end());
	m_target = &_enemys[distance(m_distanceStoreVector.begin(), itr)];
	
	//���̌�A�擾�����ԍ���Enemy��Ԃ�
	//m_player->attackhoming(&_enemys[index]);
}

void LockOn::addPlayer(Player * _player)
{
	m_player = _player;
}

void LockOn::look_at(CameraController * _camera)
{
	if (m_target == nullptr)
	{
		return;
	}
	m_target->look_at(_camera, m_player);
}

void LockOn::homing()
{
	m_player->attackhoming(m_target);
}
