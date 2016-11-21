#pragma once
#include "CollisionGroup.h"
typedef std::shared_ptr<CollisionGroup> Group_Ptr;
class CollisionManager
{
	typedef std::vector<Group_Ptr> Group;
	typedef Group::iterator Group_Itr;
public:
	CollisionManager();
	~CollisionManager();
	void add(Group_Ptr _group);
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& _renderer);
private:
	void collision();
private:
	Group m_container;
};