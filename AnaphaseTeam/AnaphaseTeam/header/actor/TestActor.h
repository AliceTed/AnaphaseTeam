#pragma once
#include "Actor.h"

#include <vector>
#include "../enemy/BreakPoint.h"
#include "../collision/CollisionManager.h"
#include "../enemy/Lock_on.h"
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
	void addCollisionGroup(CollisionManager*  _manager);
private:
	void createPoint();
	std::vector<GSvector3> getAnimEachPos();
private:
	int m_target;
	std::vector<BreakPoint> m_points;
	Lock_On m_lock_on;
	Group_Ptr m_group;
};

