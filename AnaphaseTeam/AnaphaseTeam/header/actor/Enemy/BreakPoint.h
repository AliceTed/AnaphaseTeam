#pragma once
#include "../../../header/shape/Sphere.h"
#include "../../../header/collision/CollisionActorType.h"
#include "../../../header/collision/CollisionManager.h"
#include "../../../header/math/TimeLerpVector.h"
enum class Element:unsigned int
{
	HEAD = 6,
	LEFT_LEG = 56,
	RIGHT_LEG = 61
};
class CollisionGroup;
class Enemy;
class Player;
class CameraController;
class BreakPoint
{
public:
	BreakPoint(CollisionActorType _type, Element _element);
	~BreakPoint();
	void lerp(Math::TimeLerpVector<GSvector3>& _lerp,BreakPoint& _end);
	void update(float deltaTime, std::vector<GSvector3>& _position);
	void createCollision(Enemy* _parent, Group_Ptr& _group);
	void draw(const Renderer& _renderer);
private:
	GSvector3 m_position;
	Element m_element;
	GScolor m_color;
	CollisionActorType m_type;

	Shape_Ptr shape;
	Collision_Ptr obj;
};
