#pragma once
#include "Actor.h"

#include <vector>
#include "../shape/Sphere.h"
class AttackStatus;
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();

	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void createCollision(CollisionMediator* _mediator);
	void othercollision(CollisionType _myType, CollisionType _otherType, Actor* _other);
	void collision(CollisionType _myType, CollisionType _otherType, Player* _other);
private:
	void getSphere();

	std::vector<GSmatrix4> getAnimEachPos();
	GSvector3 getPos(std::vector<GSmatrix4>& _mat, int index);
	void createEachCollsion(CollisionMediator* _mediator,unsigned int _index);
private:
	std::vector<Sphere> sphs;
	std::vector<bool>point;

	static const int HEAD = 6;
	static const int LEFTLEG = 56;
	static const int RIGHTLEG = 61;
};

