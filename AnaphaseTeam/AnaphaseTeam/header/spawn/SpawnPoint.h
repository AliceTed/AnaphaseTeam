/**
* @file SpawnPoint.h
* @brief �����p�N���X
* @author �����T��
* @date 2016/12/14
*/
#pragma once
#include <memory>
#include <vector>
#include "SpawnData.h"
class IRenderer;
class Enemy;
class EnemyFactory;
class EnemyManager;
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

	void createEnemy(EnemyManager& _manager/*,const EnemyFactory& _factory*/);
	const unsigned int getActiveNumber()const;
 	const bool isEnd()const;
private:
	std::shared_ptr<Enemy> createEnemy(/*const EnemyFactory& _factory*/);
	void remove();
private:
	SpawnData m_data;	
	Container m_container;
};