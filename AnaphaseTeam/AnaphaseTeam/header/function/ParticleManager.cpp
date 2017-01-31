#include "ParticleManager.h"
#include "renderer\IRenderer.h"
#include "function\Particle.h"
#include "function\ParticleData.h"
#include "convenient\Timer.h"
#include <random>


ParticleManager::ParticleManager() :
	m_particleData(std::make_shared<ParticleData>()),
	m_timer(std::make_shared<Timer>(2.f))
{

}

ParticleManager::~ParticleManager()
{
}

void ParticleManager::initialize()
{
}

void ParticleManager::update(float _deltaTime)
{
	m_timer->update(_deltaTime);

	//タイマーがなくなったらパーティクルを生成
	if (m_timer->isEnd()) {
		m_timer->initialize();
		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_real_distribution<> rand(0, 1230);
		m_particleData->add(Particle(GSvector2(rand(mt), 720)));
	}

	m_particleData->update(_deltaTime);
}

void ParticleManager::draw(IRenderer * _renderer)
{
	m_particleData->draw(_renderer);
}
