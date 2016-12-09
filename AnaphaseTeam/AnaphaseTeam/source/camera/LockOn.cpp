#include "../../header/camera/LockOn.h"
#include "../../header/actor/Enemy/EnemyManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/device/GameDevice.h"

LockOn::LockOn()
	:m_player(nullptr),
	m_target(nullptr)
{
}

LockOn::~LockOn()
{
}

void LockOn::nearEnemyFind(EnemyManager * _enemys)
{
	/*if (m_player == nullptr)
	{
		return;
	}*/
	//if (m_player->flg()) return;
	m_target = &_enemys->nearEnemy(m_player);
	(*m_target)->start_lockOn();
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
	if ((*m_target) == nullptr)
	{
		return;
	}
	(*m_target)->look_at(_camera, m_player);
}


void LockOn::thinksEnemy(EnemyManager * _enemys)
{
	_enemys->thinks(m_player);
}

Enemy * LockOn::getTarget() const
{
	if (m_target == nullptr)
	{
		return nullptr;
	}
	if ((*m_target) == nullptr)
	{
		return nullptr;
	}
	return m_target->get();
}
