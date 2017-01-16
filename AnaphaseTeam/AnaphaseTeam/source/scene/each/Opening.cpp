#include "scene/each/Opening.h"
#include "device/GameDevice.h"
#include "renderer/IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"
Opening::Opening()
	:m_change(),
	m_lerp(GScolor(1,1,1,0))
{
}

Opening::~Opening()
{
}

void Opening::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_lerp.start(GScolor(1,1,1,0), GScolor(1,1,1,1),7.0f);
}

void Opening::update(float deltaTime)
{
	if (m_change.update(deltaTime))return;
	m_lerp.update(deltaTime);
	if (m_lerp.isEnd()||GameDevice::getInstacnce().input()->decision())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Opening::draw(IRenderer * renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::ROGO);
	renderer->render(desc);
	m_change.draw(renderer);
}

void Opening::finish()
{
}

const SceneMode Opening::next() const
{
	return m_change.next();
}

const bool Opening::isEnd() const
{
	return m_change.isEnd();
}

const bool Opening::isExit() const
{
	return false;
}
