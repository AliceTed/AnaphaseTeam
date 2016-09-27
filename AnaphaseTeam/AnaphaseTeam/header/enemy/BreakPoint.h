#pragma once
#include "../shape/Sphere.h"
#include "../../header/collision/CollisionObject.h"
#include "../convenient/Timer.h"
enum class BreakMode
{
	Non,
	Possible,
	Break
};

class CollisionMediator;
class TestActor;
class Player;
class BreakPoint
{
public:
	BreakPoint(const Sphere& _sphere,CollisionType _type);
	~BreakPoint();
	void damage(Player* _player);
	void update(float deltaTime,const GSvector3& _position);
	void createCollision(TestActor* _parent,CollisionMediator * _mediator);
	void draw(const Renderer& _renderer);
	const bool isBreak()const;
private:
	Timer m_delay;
	BreakMode m_mode;
	Sphere m_sphere;
	GScolor m_color;
	CollisionType m_type;
};
