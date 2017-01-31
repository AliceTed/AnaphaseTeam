#include "..\..\header\ui\MenuParticle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"

MenuParticle::MenuParticle()
{
}

MenuParticle::~MenuParticle()
{
}

void MenuParticle::initialize()
{
}

void MenuParticle::update(float _deltaTime)
{
}

void MenuParticle::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::PARTICLE);
	_renderer->render(desc);
}

void MenuParticle::finish()
{
}
