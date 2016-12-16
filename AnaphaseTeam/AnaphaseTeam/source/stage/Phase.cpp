#include "..\..\header\stage\Phase.h"
#include "../../header/data/stream/SpawnReader.h"
#include "../../header/actor/ActorManager.h"
#include "../../header/camera/CameraController.h"
Phase::Phase(const PhaseData & _data)
	:m_dataname(_data.spawn),
	m_collisionMap(_data.octreeID),
	m_spawns()
{
}

void Phase::initialize()
{
	m_spawns.initialize();
	SpawnReader spawnReader;
	spawnReader(&m_spawns, m_dataname);
}

void Phase::update(float deltaTime,ActorManager& _actors, CameraController& _camera)
{
	m_spawns.update(deltaTime);
	_actors.collisionGround(m_collisionMap);
	_camera.collisionGround(m_collisionMap);
	if (m_spawns.isCurrentEnd())
	{
		_actors.createEnemy(m_spawns);
	}
}
void Phase::draw(IRenderer * _renderer)
{
	//m_collisionMap.draw(_renderer);
}

const bool Phase::isEnd() const
{
	return m_spawns.isCurrentEnd();
}
