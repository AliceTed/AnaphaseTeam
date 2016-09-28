#pragma once
#include "../shape/Sphere.h"
#include "../collision/CollisionActorType.h"
#include "../collision/TestCollisionManager.h"
enum class BreakMode
{
	Non,
	Possible,
	Break
};
class CollisionGroup;
class TestActor;
class Player;
class BreakPoint
{
public:
	BreakPoint(const Sphere& _sphere, CollisionActorType _type);
	~BreakPoint();
	void damage(Player* _player);
	void update(float deltaTime,const GSvector3& _position);
	void createCollision(TestActor* _parent, Group_Ptr& _group);
	void draw(const Renderer& _renderer);
	const bool isBreak()const;
private:
	BreakMode m_mode;
	Sphere m_sphere;
	GScolor m_color;
	CollisionActorType m_type;
};
