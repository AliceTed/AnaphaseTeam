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
#include "../../actor/Boss/Boss.h"
#include "../../actor/Enemy/Enemy.h"
#include "../../camera/LockOn.h"

#include "../../camera/CameraController.h"
#include "../SceneChange.h"
#include "../../actor/Enemy/EnemyManager.h"
class GameDevice;
typedef std::shared_ptr<Actor>Actor_Ptr;
class GamePlay :public IScene
{
public:
	GamePlay(GameDevice* _device);
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
	GameDevice* m_device;
	SceneChange m_change;
	Map m_Map;
	Camera m_Camera;
	CameraController m_cameracontroller;
	//Entity::EntityManager<Actor_Ptr> actorManager;
	CollisionManager collision;
	Player m_player;
	EnemyManager m_enemys;
	LockOn m_lockon;

};
#endif