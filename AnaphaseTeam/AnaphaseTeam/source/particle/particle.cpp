#include "../../header/particle/particle.h"
#include "../../header/renderer/Renderer.h"

const float Particle::GRAVITY = 0.01f;

Particle::Particle()
	:m_textureID(TEXTURE_ID::EXIT),
	m_isDead(false),
	m_position(0.0f, 5.0f, -5.0f),
	m_velocity(0.0f, 0.0f, 0.0f)

{
}

void Particle::setTextureID(TEXTURE_ID textureID)
{
	m_textureID = textureID;
}

void Particle::setPosition(const GSvector3 & position)
{
	m_position = position;
}

void Particle::setVelocity(const GSvector3 & velocity)
{
	m_velocity = velocity;
}

TEXTURE_ID Particle::getTextureID() const
{
	return m_textureID;
}

const GSvector3 & Particle::getPosition() const
{
	return m_position;
}

const GSvector3 & Particle::getVelocity() const
{
	return m_velocity;
}

void Particle::update(float _deltaTime)
{
	//m_position += m_velocity *_deltaTime;
	//m_velocity.y -= GRAVITY;
	m_isDead = (m_position.y < 0.0f);
}

void Particle::draw(const Renderer& _renderer)
{
	_renderer.getDraw3D().drawTexture(m_textureID,&m_position);
}

bool Particle::isDead() const
{
	return m_isDead;
}
