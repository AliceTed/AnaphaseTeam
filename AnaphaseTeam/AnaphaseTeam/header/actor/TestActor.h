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
	void createCollision(CollisionMediator* _mediator);
	void collision(const Actor* _other);
	//!Debug用描画カウント変数
	static int DrawCount;
private:
	GSvector3 target;
	Animation animation;
};

