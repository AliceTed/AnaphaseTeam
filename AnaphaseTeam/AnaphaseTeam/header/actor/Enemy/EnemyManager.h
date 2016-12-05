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
	void draw(IRenderer * _renderer);
	Enemy_Ptr& nearEnemy(Player* _player);

	void thinks(Player* _player);

	const unsigned int size()const;
private:
	EnemyManager(EnemyManager&);
	EnemyManager& operator=(EnemyManager&);
private:
	void remove();
private:
	std::vector<Enemy_Ptr>m_enemys;
};
