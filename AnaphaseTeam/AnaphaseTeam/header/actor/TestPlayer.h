#pragma once
/**
* @file TestPlayer.h
* @brief テスト用プレイヤークラス
* @author 松尾裕也
* @date 2016/8/17
*/
#include"Actor.h"
#include "../animation/Animation.h"
#include "../animation/AnimationTimer.h"
#include "TestJump.h"
#include "TestChainMove.h"
#include "../convenient/Timer.h"
class Input;
class TestPlayer:public Actor
{
public:
	TestPlayer(const Input* _input);
	~TestPlayer();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void collisionGround(const Map& _map);
	void createCollision(CollisionMediator* _mediator);

	void move(float deltaTime);
	void jump(float deltaTime);
	void chain(float deltaTime);

	void jumping(float _velocity);
	void chainMove(const GSvector3 & _target, float _time);
private:
	const Input* m_Input;
	Animation animation;

	TestJump m_Jump;
	TestChainMove m_ChainMove;

	static const float MOVESPEED;
	static const float ROTATESPEED;
};

