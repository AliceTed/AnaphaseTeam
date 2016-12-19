#pragma once
#include "../camera/CameraController.h"
#include "../map/Map.h"
#include "../actor/ActorManager.h"
#include "PhaseManager.h"
struct StageData;
class Stage
{
public:
	Stage(const StageData& _stage);
	~Stage();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);	
	const bool isClear()const;
	const bool isDead()const;
private:
	void finish();
private:
	Map m_Map;
	CameraController m_cameracontroller;
	ActorManager m_actors;
	PhaseManager m_phaseManage;
};
