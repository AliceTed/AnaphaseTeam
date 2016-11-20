#pragma once
#include "../Actor.h"
#include "../../collision/CollisionManager.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
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
	DAMAGE
};

class Enemy :public Actor
{
public:
	Enemy(const Transform& _transform);
	void addCollisionGroup(CollisionManager*  _manager)override;
	void initialize() override;
	void update(float deltatime)override;
	void draw(const Renderer& _renderer, const Camera& _camera)override;
public:
	void collisionChase(EnemyCollision* _collision);
	void damage(Player* _player);
	void look_at(CameraController* _camera, Player* _player);

	void think(Player* _palyer);
private:
	const bool isNear(float _distance)const;
	void state(float deltaTime);
	const bool isDamageState()const;
private:
	void slide(Actor* _actor);
	void move(Actor* _actor);
private:
	Group_Ptr m_group;
	ESTATE m_state;
	Timer m_stay_timer;
	GSvector3 m_velocity;
	GSquaternion m_rotate;
	static const float PLAYER_DISTANCE;
	float m_hp;
};
