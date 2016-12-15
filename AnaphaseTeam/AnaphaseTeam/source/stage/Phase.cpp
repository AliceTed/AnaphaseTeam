#include "..\..\header\stage\Phase.h"
#include "../../header/data/stream/SpawnReader.h"
#include "../../header/actor/ActorManager.h"
Phase::Phase(const PhaseData & _data)
	:m_collisionMap(_data.m_octreeID),
	m_spawns()
{
	m_spawns.initialize();
	SpawnReader spawnReader;
	spawnReader(&m_spawns,_data.spawn);
}

void Phase::update(float deltaTime,ActorManager& _actors)
{
	m_spawns.update(deltaTime);
	_actors.collisionGround(m_collisionMap);
	if (m_spawns.isCurrentEnd())
	{
		_actors.createEnemy(m_spawns);
	}
}

void Phase::draw(IRenderer * _renderer)
{
	m_spawns.draw(_renderer);
}

const bool Phase::isEnd() const
{
	return m_spawns.isCurrentEnd();
}
