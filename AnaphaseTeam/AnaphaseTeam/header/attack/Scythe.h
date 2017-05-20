/**
* @file Scythe.h
* @brief 鎌攻撃
* @author 吉元雅喜
* @date 2016/09/01
*/
#pragma once
#include "../transform/Transform.h"
class IRenderer;
class Animator;
class Scythe
{
public:
	Scythe();
	~Scythe();
	void initialize();
	//リファクタ
	void update(float deltaTime, const Animator& _animator, const Transform& _parent);
	void draw(IRenderer * _renderer);
private:
	Transform m_local;
	Transform m_world;
	GSuint m_bone;
};