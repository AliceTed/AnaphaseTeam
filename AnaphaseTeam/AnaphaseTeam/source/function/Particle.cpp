#include "function\Particle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"


Particle::Particle(const GSvector3 _pos, TEXTURE_ID _id) :
	m_texID(_id),
	m_pos(_pos)
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
	desc.matrix.setTranslation(m_pos);
	_renderer->render(desc);
}
