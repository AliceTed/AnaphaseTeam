#pragma once
#include "CollisionActor.h"
class Actor;
class CollisionGroup
{
public:
	CollisionGroup(Actor* _actor);
	~CollisionGroup();
	void add(Collision_Ptr _collision);
	void initialize();
	void update(float deltaTime);
	void collision(CollisionGroup& _group);
	void draw(const Renderer& _renderer);

	unsigned int size()const;
private:
	void remove();
	void collision(Collision_Ptr& _my, Collision_Ptr& _other, Actor* _actor);
private:
	//ÉRÉsÅ[ã÷é~
	CollisionGroup(const CollisionGroup&);
	CollisionGroup& operator=(const CollisionGroup&);
private:
	Actor* m_actor;
	std::vector<Collision_Ptr> m_container;
};