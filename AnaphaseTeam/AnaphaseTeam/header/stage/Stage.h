#pragma once
#include "../camera/CameraController.h"
#include "../map/Map.h"
#include "../actor/ActorManager.h"
#include "PhaseManager.h"
#include "../ui/Score.h"
struct StageData;
class Stage
{
public:
	Stage(const StageData& _stage);
	~Stage();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	void add(int _score);
	const bool isClear()const;
	const bool isDead()const;
private:
	void finish();
private:
	Map m_Map;
	std::shared_ptr<Score> m_score;
	CameraController m_cameracontroller;
	ActorManager m_actors;
	PhaseManager m_phaseManage;
};
