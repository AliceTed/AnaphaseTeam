#pragma once
#include "PhaseData.h"
#include "../map/Map.h"
#include "../spawn/SpawnManager.h"
class IRenderer;
class ActorManager;
class Phase
{
public:
	Phase(const PhaseData& _data);
	~Phase()=default;
	void initialize();
	void update(float deltaTime, ActorManager& _actors);
	void draw(IRenderer* _renderer);
	const bool isEnd()const;
private:
	std::string m_dataname;
	Map m_collisionMap;
	SpawnManager m_spawns;
};