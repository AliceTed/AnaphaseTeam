#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "../IScene.h"
#include "../../camera/Camera.h"
#include "../../actor/Actor.h"
#include "../../entity/EntityManager.h"
#include "../../map/Map.h"
#include "../../collision/CollisionManager.h"
#include <memory>
#include "../../actor/Player/Player.h"
#include "../../actor/Enemy/Enemy.h"

#include "../../actor/TestActor.h"
#include "../../camera/CameraController.h"
#include "../SceneChange.h"
class Input;
typedef std::shared_ptr<Actor>Actor_Ptr;
class GamePlay :public IScene
{
public:
	GamePlay(const Input* _input);
	~GamePlay();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	const Input* m_Input;
	SceneChange m_change;
	Map m_Map;
	Camera m_Camera;
	CameraController m_cameracontroller;
	Entity::EntityManager<Actor_Ptr> actorManager;
	CollisionManager collision;
	Player m_player;
	Enemy m_boss;
	//TestActor m_boss;
};
#endif