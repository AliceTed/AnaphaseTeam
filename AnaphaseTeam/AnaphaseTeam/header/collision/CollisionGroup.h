#pragma once
#include "CollisionActor.h"
#include "../actor/Actor.h"
typedef std::shared_ptr<Actor> Actor_Ptr;
typedef std::shared_ptr<CollisionActor> Collision_Ptr;
class CollisionGroup
{
public:
	CollisionGroup(Actor_Ptr _actor);
	~CollisionGroup();
	void add(Collision_Ptr _collision);
	void initialize();
	void update(float deltaTime);
	void collision(CollisionGroup& _group);
	void draw(const Renderer& _renderer);
private:
	void for_each(std::vector<Collision_Ptr>& _vector,const std::function<void(Collision_Ptr _collision)>& _func);
	void collision(Collision_Ptr _my, Collision_Ptr _other,Actor_Ptr _actor);
private:
	Actor_Ptr m_actor;
	std::vector<Collision_Ptr> m_container;
};