#pragma once

#include <vector>
#include "../Actor.h"
#include "../Enemy/BreakPoint.h"
#include "../../collision/CollisionManager.h"
using namespace std;

class Player;
class AttackStatus;
class CameraController;

class Enemy : public Actor
{
public:
	Enemy();
	~Enemy();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void look_at(CameraController* _camera, Player* _player);
	void addCollisionGroup(CollisionManager*  _manager);
private:
	void createPoint();
	vector<GSvector3> getAnimEachPos();
private:
	vector<BreakPoint> m_points;
	Sphere m_core;
	GScolor m_corecolor;
	Group_Ptr m_group;

};