#pragma once
#include "Actor.h"

#include <unordered_map>
#include "../enemy/BreakPoint.h"
class AttackStatus;
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void createCollision(CollisionMediator* _mediator);
private:
	void add(const Sphere& _sphere,CollisionType _type);
	void createPoint();
	void eachUpdate(float deltaTime, CollisionType _type,const GSvector3& _position);

	std::vector<GSmatrix4> getAnimEachPos();
	GSvector3 getPos(std::vector<GSmatrix4>& _mat, int index);
private:
	std::unordered_map<CollisionType,BreakPoint> m_points;
	Sphere m_core;
	GScolor m_color;
	static const int HEAD = 6;
	static const int LEFTLEG = 56;
	static const int RIGHTLEG = 61;
};

