#pragma once
#include <vector>
#include "Enemy.h"
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager() = default;
	void initialize();
	void add(const Enemy& _enemy);
	void update(float deltaTime);
	void collisionGround(const Map& _map);
	void draw(const Renderer& _renderer,const Camera& _camera);
private:
	void remove();
private:
	std::vector<Enemy>m_enemys;
};
