/**
* @file Scythe.h
* @brief ���U��
* @author �g�����
* @date 2016/09/01
*/
#pragma once
#include "../transform/Transform.h"
class Renderer;
class AnimatorOne;
class CollisionGroup;
class Scythe
{
public:
	Scythe();
	~Scythe();
	void initialize();
	void addCollision(CollisionGroup* _group);
	//���t�@�N�^
	void update(float deltaTime, const AnimatorOne& _animator, const Transform& _parent);
	void draw(const Renderer& _renderer);
private:
	Transform m_local;
	Transform m_world;
	Transform m_collision;
	Transform m_collision_world;
	GSuint m_bone;
};