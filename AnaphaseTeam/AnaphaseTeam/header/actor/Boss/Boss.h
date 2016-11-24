#pragma once

#include <vector>
#include <memory>
#include "../Actor.h"
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
	void draw(IRenderer * _renderer, const Camera& _camera);
	void look_at(CameraController* _camera, Player* _player);
public:
	const GSvector3 getPosition() const;

private:
	vector<GSvector3> getAnimEachPos();

	void enemyAttack();
	void dirCalc(Player* _player);

private:
	Sphere m_core;
	GScolor m_corecolor;
	vector<GSvector3> pos;
	GScolor m_color;
	int m_value;
	State m_state;
};