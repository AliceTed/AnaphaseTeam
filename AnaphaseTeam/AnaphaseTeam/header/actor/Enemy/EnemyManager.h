#pragma once
#include <vector>
#include "Enemy.h"
#include <memory>
typedef std::unique_ptr<Enemy> Enemy_Ptr;
class EnemyManager
{
	
public:
	EnemyManager();
	~EnemyManager() = default;
	//ムーブコンストラクタ
	EnemyManager(EnemyManager&&) = default;
	void initialize();
	void add(Enemy* _enemy);
	void update(float deltaTime);
	void collisionGround(const Map& _map);

	void collision(Actor& _actor);
	void draw(const Renderer& _renderer,const Camera& _camera);
	Enemy_Ptr& nearEnemy(Player* _player);

	void thinks(Player* _player);
	int size();
private:
	EnemyManager(EnemyManager&);
	EnemyManager& operator=(EnemyManager&);
private:
	void remove();
private:
	std::vector<Enemy_Ptr>m_enemys;
};
