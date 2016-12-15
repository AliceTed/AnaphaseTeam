#include "../../header/camera/LockOn.h"
#include "../../header/actor/Enemy/EnemyManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/device/GameDevice.h"
#include "../../header/actor/Enemy/Enemy.h"
LockOn::LockOn()
	:m_player(nullptr),
	m_target()
{
}

LockOn::~LockOn()
{
}

void LockOn::nearEnemyFind(EnemyManager * _enemys)
{
	if (m_player == nullptr)return;
	m_target =_enemys->nearEnemy(m_player);
	m_target.lock()->start_lockOn();
}

void LockOn::addPlayer(Player * _player)
{
	m_player = _player;
}

void LockOn::look_at(CameraController * _camera)
{
	if (m_target.expired())return;
	m_target.lock()->look_at(_camera, m_player);
}


void LockOn::thinksEnemy(EnemyManager * _enemys)
{
	_enemys->thinks(m_player);
}

std::weak_ptr<Enemy> LockOn::getTarget() const
{
	return m_target;
}
