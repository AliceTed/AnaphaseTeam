#include "function\ParticleManager.h"
#include "renderer\IRenderer.h"
#include "function\Particle.h"
#include "function\ParticleData.h"
#include "convenient\Timer.h"
#include <random>


ParticleManager::ParticleManager() :
	m_particleData(std::make_shared<ParticleData>()),
	m_timer1(std::make_shared<Timer>(2.f)),
	m_timer2(std::make_shared<Timer>(1.f)),
	m_timer3(std::make_shared<Timer>(3.f))
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
	m_timer1->update(_deltaTime);
	m_timer2->update(_deltaTime);
	m_timer3->update(_deltaTime);

	//タイマーがなくなったらパーティクルを生成
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_real_distribution<> rand(0, 1230);
	if (m_timer1->isEnd()) {
		m_timer1->initialize();
		m_particleData->add(Particle(GSvector2(rand(mt), 720)));
	}
	if (m_timer2->isEnd()) {
		m_timer2->initialize();
		m_particleData->add(Particle(GSvector2(rand(mt), 720)));
	}
	if (m_timer3->isEnd()) {
		m_timer3->initialize();
		m_particleData->add(Particle(GSvector2(rand(mt), 720)));
	}

	m_particleData->update(_deltaTime);
}

void ParticleManager::draw(IRenderer * _renderer)
{
	m_particleData->draw(_renderer);
}
