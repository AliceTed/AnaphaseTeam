#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "../IScene.h"
#include "../../actor/Player/Player.h"
#include "../../camera/Camera.h"
#include "../../actor/Actor.h"
#include "../../entity/EntityManager.h"
#include "../../map/Map.h"
#include <memory>
#include <gslib.h>
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
private:
	bool m_IsEnd;
	const Input* m_Input;
	Map m_Map;
	Camera m_Camera;
	Entity::EntityManager<Actor_Ptr> actorManager;
	Player m_player;

};
#endif