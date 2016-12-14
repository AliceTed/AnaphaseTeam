/**
* @file SpawnPoint.h
* @brief ¶¬—pƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/12/14
*/
#pragma once
#include <memory>
#include <vector>
#include "SpawnData.h"
class IRenderer;
class Enemy;
class EnemyFactory;
class SpawnPoint
{
	using EnemyWeak_Ptr = std::weak_ptr<Enemy>;
	using Container = std::vector<EnemyWeak_Ptr>;
public:
	SpawnPoint(const SpawnData& _data);
	~SpawnPoint()=default;
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);

	const unsigned int getActiveNumber()const;
	std::shared_ptr<Enemy> createEnemy(const EnemyFactory& _factory);
 	const bool isEnd()const;
private:
	void remove();
private:
	bool m_isStart;
	SpawnData m_data;	
	Container m_container;
};