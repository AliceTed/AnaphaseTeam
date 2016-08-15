#pragma once
#include "Actor.h"

class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
private:
	GSvector3 target;
};

