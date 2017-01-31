#include "function\Particle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"


Particle::Particle(TEXTURE_ID _id) :
	m_texID(_id)
{
}

Particle::~Particle()
{
}

void Particle::initialize()
{
}

void Particle::update(float _deltaTime)
{
}

void Particle::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_texID);
	_renderer->render(desc);
}
