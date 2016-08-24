#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"
#include "../../camera/Camera.h"
#include "../../actor/Actor.h"
#include "../../entity/EntityManager.h"
#include "../../map/Map.h"
#include <memory>
#include "../../actor/TestPlayer.h"

#include "../../collision/CollisionManager.h"

#include"../../shape/OBB.h"
#include "../../shape/Capsule.h"
class Input;
typedef std::shared_ptr<Actor>Actor_Ptr;
class Title :public IScene
{
public:
	Title(const Input* _input);
	~Title();
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
	TestPlayer player;
	CollisionManager collision;

	OBB ob1;
	Capsule cap;
};
#endif