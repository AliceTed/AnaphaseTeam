/**
* @file Scythe.h
* @brief ���U��
* @author �g�����
* @date 2016/09/01
*/
#pragma once
#include "../transform/Transform.h"
class IRenderer;
class AnimatorOne;
class CollisionGroup;
class Scythe
{
public:
	Scythe();
	~Scythe();
	void initialize();
	//���t�@�N�^
	void update(float deltaTime, const AnimatorOne& _animator, const Transform& _parent);
	void draw(IRenderer * _renderer);
private:
	Transform m_local;
	Transform m_world;
	GSuint m_bone;
};