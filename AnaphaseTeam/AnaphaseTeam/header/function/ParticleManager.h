/**
@file
@brief	パーティクルマネージャー
@author Yuuho Aritomi
@date	2017/01/31
*/
#pragma once

#include <memory>

class IRenderer;
class ParticleData;
class Timer;

class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
private:
	std::shared_ptr<ParticleData> m_particleData;
	std::shared_ptr<Timer> m_timer;
};
