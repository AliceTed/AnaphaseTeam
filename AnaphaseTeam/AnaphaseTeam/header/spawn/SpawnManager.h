/**
* @file SpawnManager.h
* @brief ¶¬‚ÌŠÇ—ƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/12/14
*/
#pragma once
#include "SpawnPoint.h"
#include "spawn\EnemyFactory.h"
class EnemyManager;
class SpawnManager
{
public:
	SpawnManager();
	~SpawnManager() = default;
	void initialize();
	void add(const SpawnPoint& _point);
	void update(float deltaTime);
	void draw(IRenderer *_renderer);
	void createEnemy(EnemyManager& _enemyManager);
	const bool isCurrentEnd()const;
	const bool isEnd()const;
private:
	void remove();
	void move();	
private:
	using Container = std::vector<SpawnPoint>;
	Container m_container;
	Container m_current;
	EnemyFactory m_factory;
};
