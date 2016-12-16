#pragma once
#include "../camera/CameraController.h"
#include "../map/Map.h"
#include "../actor/ActorManager.h"
#include "PhaseManager.h"
class Stage
{
public:
	Stage(const Transform& _init);
	~Stage()=default;
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	void finish();
	const bool isClear()const;
	const bool isDead()const;
private:
	Map m_Map;
	CameraController m_cameracontroller;
	ActorManager m_actors;

	PhaseManager m_pahsemanager;
};
