#pragma once
#include "Actor.h"

#include <vector>
#include "../enemy/BreakPoint.h"
class Player;
class AttackStatus;
class CameraController;
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void look_at(CameraController* _camera,Player* _actor);
	void addCollisionGroup(TestCollisionManager*  _manager);
private:
	void createPoint();
	std::vector<GSvector3> getAnimEachPos();
private:
	std::vector<BreakPoint> m_points;
	Sphere m_core;
	GScolor m_corecolor;
	Group_Ptr m_group;
};

