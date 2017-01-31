#include "function\Particle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"
#include "math\Calculate.h"


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
	GSvector3 gravity = GSvector3(0.f, -1.f, 0.f);

	m_pos += gravity;
}

void Particle::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_texID);
	desc.matrix.setTranslation(m_pos);
	_renderer->render(desc);
}
