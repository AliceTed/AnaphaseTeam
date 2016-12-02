#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
//#include "../../attack/AttackIncidence.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
class EnemyCollision;
class Player;
//éÊÇËÇ†Ç¶Ç∏enumÇ≈èÛë‘ï™ÇØ
enum class ESTATE
{
	SPAWN,
	STAND,
	MOVE,
	SLIDE,
	ATTACK,
	DAMAGE,
	DEAD
};

class Enemy :public Actor
{
public:
	Enemy(const Transform& _transform);
	~Enemy();
	void initialize() override;
	void update(float deltatime)override;
	void draw(IRenderer* _renderer)override;
	void damage(const AttackStatus& _attackStatus)override;
public:
	void collisionChase(EnemyCollision* _collision);
	void damage(Player* _player);
	void look_at(CameraController* _camera, Player* _player);
	void specialDamage();

	void think(Player* _palyer);
private:
	const bool isNear(float _distance)const;
	void state(float deltaTime);
	const bool isDamageState()const;
	void createStates();
private:
	void slide(Actor* _actor);
	void move(Actor* _actor);
	void attack_start();
	void stay_start();
private:
	Timer m_stay_timer;
	static const float PLAYER_DISTANCE;
	float m_alpha;
	Status m_status;

private://state
	class EAttackState;
	class EDamageState;
	class EMoveState;
	class EStandState;
	class ESlideState;
	class ESpawnState;
	class EDeadState;

	friend EAttackState;
	friend EDamageState;
	friend EMoveState;
	friend EStandState;
	friend ESlideState;
	friend ESpawnState;
	friend EDeadState;

};
