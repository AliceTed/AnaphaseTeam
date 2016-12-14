/**
* @file SpawnManager.h
* @brief ¶¬‚ÌŠÇ—ƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/12/14
*/
#pragma once
#include "SpawnPoint.h"
class SpawnManager
{
public:
	SpawnManager();
	~SpawnManager() = default;
	void add(const SpawnPoint& _point);
	void update(float deltaTime);
	void draw(IRenderer *_renderer);
private:
	//~‡
	void sort();
	void remove();
private:
	using Container = std::vector<SpawnPoint>;
	Container m_container;
};
