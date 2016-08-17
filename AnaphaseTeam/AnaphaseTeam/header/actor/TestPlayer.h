#pragma once
/**
* @file TestPlayer.h
* @brief �e�X�g�p�v���C���[�N���X
* @author �����T��
* @date 2016/8/17
*/
#include"Actor.h"
#include "../animation/Animation.h"
#include "../animation/AnimationTimer.h"
#include "TestJump.h"
class Input;
class TestPlayer:public Actor
{
public:
	TestPlayer(const Input* _input);
	~TestPlayer();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void collisionGround(const Map& _map);

	void jump(float _velocity);
private:
	const Input* m_Input;
	Animation animation;
	TestJump m_Jump;

};

