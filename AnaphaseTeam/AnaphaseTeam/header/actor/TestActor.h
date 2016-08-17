#pragma once
#include "Actor.h"
#include "../animation/Animation.h"
#include "../animation/AnimationTimer.h"
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();

	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	//!Debug�p�`��J�E���g�ϐ�
	static int DrawCount;
private:
	GSvector3 target;
	Animation animation;
};

