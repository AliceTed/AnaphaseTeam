#include "ParticleManager.h"
#include "renderer\IRenderer.h"
#include "function\Particle.h"
#include "function\ParticleData.h"
#include "convenient\Timer.h"


ParticleManager::ParticleManager() :
	m_particleData(std::make_shared<ParticleData>()),
	m_timer(std::make_shared<Timer>(10.f))
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

	if (m_timer->isEnd()) {
		m_timer->initialize();
		m_particleData->add(Particle(GSvector2(640, 720)));
	}

	m_particleData->update(_deltaTime);
}

void ParticleManager::draw(IRenderer * _renderer)
{
	m_particleData->draw(_renderer);
}
