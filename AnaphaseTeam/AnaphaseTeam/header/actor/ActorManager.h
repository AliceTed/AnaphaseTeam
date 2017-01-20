/**
* @file ActorManageer.h
* @brief アクター管理用
* @author 松尾裕也
* @date 2016/12/15
*/
#pragma once
#include "Enemy/EnemyManager.h"
#include "Player/Player.h"
#include "../camera/LockOn.h"
#include <memory>
class IRenderer;
class Player;
class SpawnManager;
class ActorManager
{
public:
	ActorManager(const Transform& _player,Camera* _camera, Score & _score);
	~ActorManager()=default;
	void initialize();
	void update(float deltaTime);
	void collisionGround(const Map& _map);
	void draw(IRenderer* _renderer);
	void finish();
	void lockAt(CameraController* _camera);
	void createEnemy(SpawnManager& _spawn);

	const bool isPlayerDead()const;
private:
	using PlayerPtr = std::shared_ptr<Player>;
	PlayerPtr m_player;
	EnemyManager m_enemys;
	
	LockOn m_lockon;
};