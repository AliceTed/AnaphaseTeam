#include "../../header/camera/LockOn.h"
#include "../../header/actor/Enemy/EnemyManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/device/GameDevice.h"

LockOn::LockOn(GameDevice* _device)
	:m_player(nullptr),
	m_target(nullptr),
	m_device(_device)
{
}

LockOn::~LockOn()
{
}

void LockOn::nearEnemyFind(EnemyManager * _enemys)
{
	if (m_player == nullptr)
	{
		return;
	}
	if (m_target == nullptr || m_device->input()->lockOn())
	{
		m_target = &_enemys->nearEnemy(m_player);
	}
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

void LockOn::homing()
{
	m_player->attackHoming((*m_target).get());
}

void LockOn::thinksEnemy(EnemyManager * _enemys)
{
	_enemys->thinks(m_player);
}
