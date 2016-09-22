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
private:
	void getSphere();

	std::vector<GSmatrix4> getAnimEachPos();
	GSvector3 getPos(std::vector<GSmatrix4>& _mat, int index);
private:
	std::vector<Sphere> sphs;

	static const int HEAD = 6;
	static const int LEFTLEG = 56;
	static const int RIGHTLEG = 61;
};

