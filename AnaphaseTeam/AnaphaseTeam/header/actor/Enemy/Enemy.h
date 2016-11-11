#pragma once
#include "../Actor.h"
#include "../../collision/CollisionManager.h"
class EnemyCollision;
class Player;
//éÊÇËÇ†Ç¶Ç∏enumÇ≈èÛë‘ï™ÇØ
enum class ESTATE
{
	SPAWN,
	STAND,
	MOVE,
	ATTACK,
	DAMAGE
};

class Enemy :public Actor
{
public:
	Enemy(const Transform& _transform);
	~Enemy() = default;
	void addCollisionGroup(CollisionManager*  _manager)override;
	void initialize() override;
	void update(float deltatime)override;
	void draw(const Renderer& _renderer, const Camera& _camera)override;
public:
	void collisionChase(EnemyCollision* _collision);
	void damage(Player* _player);
private:
	void state();
	const bool isDamageState()const;
private:
	Group_Ptr m_group;
	ESTATE m_state;
};
