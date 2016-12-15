#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "../IScene.h"
#include "../../camera/Camera.h"
#include "../../camera/CameraController.h"
#include "../../map/Map.h"
#include "../SceneChange.h"
#include "Pause.h" 
#include "../../actor/ActorManager.h"
#include "../../stage/PhaseManager.h"
class GamePlay :public IScene
{
public:
	GamePlay();
	~GamePlay();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * renderer);
	void finish();

	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	SceneChange m_change;
	Map m_Map;
	Camera m_Camera;
	CameraController m_cameracontroller;
	ActorManager m_actors;
	Pause m_pause;
	PhaseManager m_pahsemanager;
};
#endif