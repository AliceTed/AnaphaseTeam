#pragma once
#include "Actor.h"
#include "../animation/Animation.h"
#include "../animation/AnimationTimer.h"
#include "../animation/Animator.h"
class AttackStatus;
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();

	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void createCollision(CollisionMediator* _mediator);
	void collision(Actor* _other);
	/*
	�U���͂Ɛ�����ђl���󂯎��
	*/
	void beUnderAttack(float _attackPower, const GSvector3& _blowOffPower);
	//!Debug�p�`��J�E���g�ϐ�
	static int DrawCount;
private:
	GSvector3 target;
};

