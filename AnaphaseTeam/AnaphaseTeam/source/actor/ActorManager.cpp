#include "..\..\header\actor\ActorManager.h"
#include "../../header/spawn/SpawnManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/ui/Score.h"
ActorManager::ActorManager(const Transform& _player, Camera* _camera,Score & _score)
	:m_lockon(),
	m_player(std::make_unique<Player>(_player,_camera, &m_lockon)),
	m_enemys(m_player.get(),_score)
{

}

void ActorManager::initialize()
{
	m_player->initialize();
	m_enemys.initialize();
	m_lockon.addPlayer(m_player.get());
}

void ActorManager::update(float deltaTime)
{
	m_lockon.thinksEnemy(&m_enemys);
	m_player->targetFind(&m_enemys);
	m_player->update(deltaTime);
	m_enemys.update(deltaTime);
	m_enemys.collision(*m_player.get());
	m_lockon.update(deltaTime);
}

void ActorManager::collisionGround(const Map & _map)
{
	m_player->collisionGround(_map);
	m_enemys.collisionGround(_map);
}

void ActorManager::draw(IRenderer * _renderer)
{
	m_enemys.draw(_renderer);
	m_player->draw(_renderer);
}

void ActorManager::finish()
{
	m_player->finish();
}

void ActorManager::lockAt(CameraController * _camera)
{
	m_lockon.look_at(_camera);
}
void ActorManager::createEnemy(SpawnManager & _spawn)
{
	_spawn.createEnemy(m_enemys);
}

const bool ActorManager::isPlayerDead() const
{
	return m_player->isDead();
}
