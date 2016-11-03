#pragma once

#include <vector>
#include <memory>
#include "../Actor.h"
#include "../Boss/BreakPoint.h"
#include "../../collision/CollisionManager.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Player;
class AttackStatus;
class CameraController;


enum class State
{
	STAND,
	ATTACK
};

class Boss : public Actor
{
public:
	Boss();
	~Boss();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void look_at(CameraController* _camera, Player* _player);
	void addCollisionGroup(CollisionManager*  _manager);

public:
	const GSvector3 getPosition() const;

private:
	void createPoint();
	vector<GSvector3> getAnimEachPos();

	void enemyAttack();
	void dirCalc(Player* _player);

private:
	vector<BreakPoint> m_points;
	Sphere m_core;
	GScolor m_corecolor;
	Group_Ptr m_group;
	vector<GSvector3> pos;
	GScolor m_color;
	int m_value;
	State m_state;
};