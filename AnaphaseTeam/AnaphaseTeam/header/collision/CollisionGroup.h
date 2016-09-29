#pragma once
#include "CollisionActor.h"
class Actor;
typedef std::shared_ptr<CollisionActor> Collision_Ptr;
class CollisionGroup
{
public:
	CollisionGroup(Actor* _actor);
	~CollisionGroup();
	void add(Collision_Ptr _collision);
	void initialize();
	void update(float deltaTime);
	void remove();
	void collision(CollisionGroup& _group);
	void draw(const Renderer& _renderer);
private:
	void for_each(std::vector<Collision_Ptr>& _vector,std::function<void(Collision_Ptr _collision)> _func);
	void collision(Collision_Ptr _my, Collision_Ptr _other, Actor* _actor);
private:
	Actor* m_actor;
	std::vector<Collision_Ptr> m_container;
};