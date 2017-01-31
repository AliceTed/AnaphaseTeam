#include "..\..\header\function\ParticleData.h"
#include "function\Particle.h"
#include <algorithm>
#include <functional>

ParticleData::ParticleData() :
	m_particles()
{
}

ParticleData::~ParticleData()
{
}

void ParticleData::update(float _deltaTime)
{
	//XV
	ParticleContaner::iterator itr = m_particles.begin();
	while (itr != m_particles.end()) {
		(*itr)->update(_deltaTime);
		itr++;
	}

	//Ž€‚ñ‚Å‚é‚È‚çíœ
	itr = m_particles.begin();
	while (itr != m_particles.end()) {
		if ((*itr)->isDead()) {
			m_particles.erase(itr);
			return;
		}
		itr++;
	}
}

void ParticleData::draw(IRenderer * _renderer)
{
	ParticleContaner::iterator itr = m_particles.begin();
	while (itr != m_particles.end())
	{
		(*itr)->draw(_renderer);
		itr++;
	}
}

void ParticleData::add(Particle _object)
{
	m_particles.emplace_back(std::make_shared<Particle>(_object));
}
