#include "..\..\header\ui\MenuParticle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"
#include "function\ParticleManager.h"
#include <gslib.h>

MenuParticle::MenuParticle() :
	m_particle(std::make_unique<ParticleManager>())
{

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
