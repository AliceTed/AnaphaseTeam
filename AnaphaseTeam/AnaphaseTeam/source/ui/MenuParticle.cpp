#include "..\..\header\ui\MenuParticle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"
#include "function\Particle.h"
#include "function\ParticleData.h"
#include <gslib.h>

MenuParticle::MenuParticle() :
	m_particle(std::make_unique<ParticleData>())
{
	m_particle->add(Particle(GSvector2(640.f, 720.f)));
}

MenuParticle::~MenuParticle()
{
}

void MenuParticle::initialize()
{
	m_particle->initialize();
}

void MenuParticle::update(float _deltaTime)
{
	m_particle->update(_deltaTime);
}

void MenuParticle::draw(IRenderer * _renderer)
{
	m_particle->draw(_renderer);
}

void MenuParticle::finish()
{
}
