#pragma once
#include "../shape/Sphere.h"
#include "../collision/CollisionActorType.h"
#include "../collision/CollisionManager.h"
#include "../math/TimeLerpVector.h"
enum class Element:unsigned int
{
	HEAD=6,
	LEFT_LEG=56,
	RIGHT_LEG= 61
};
class CollisionGroup;
class TestActor;
class Player;
class CameraController;
class BreakPoint
{
public:
	BreakPoint(CollisionActorType _type,Element _element);
	~BreakPoint();
	void lerp(Math::TimeLerpVector<GSvector3>& _lerp,BreakPoint& _end);
	void update(float deltaTime, std::vector<GSvector3>& _position);
	void createCollision(TestActor* _parent, Group_Ptr& _group);
	void draw(const Renderer& _renderer);
private:
	GSvector3 m_position;
	Element m_element;
	GScolor m_color;
	CollisionActorType m_type;
};
