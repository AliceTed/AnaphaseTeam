#pragma once
#include "../shape/Sphere.h"
#include "../collision/CollisionActorType.h"
#include "../collision/TestCollisionManager.h"

enum class Element:unsigned int
{
	HEAD=6,
	LEFT_LEG=56,
	RIGHT_LEG= 61
};
class CollisionGroup;
class TestActor;
class Player;
class BreakPoint
{
public:
	BreakPoint(CollisionActorType _type,Element _element);
	~BreakPoint();
	void update(float deltaTime, std::vector<GSvector3>& _position);
	void createCollision(TestActor* _parent, Group_Ptr& _group);
	void draw(const Renderer& _renderer);
private:
	bool i = false;
	GSvector3 m_position;
	Element m_element;
	GScolor m_color;
	CollisionActorType m_type;
};
