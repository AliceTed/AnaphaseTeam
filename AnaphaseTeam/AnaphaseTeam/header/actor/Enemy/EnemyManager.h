#pragma once
#include <vector>
#include "Enemy.h"
#include <memory>
class EnemyManager
{
	typedef std::unique_ptr<Enemy> Enemy_Ptr;
public:
	EnemyManager();
	~EnemyManager() = default;
	void initialize();
	void add(Enemy* _enemy);
	void update(float deltaTime);
	void collisionGround(const Map& _map);
	void draw(const Renderer& _renderer,const Camera& _camera);
private:
	void remove();
private:
	std::vector<Enemy_Ptr>m_enemys;
};
