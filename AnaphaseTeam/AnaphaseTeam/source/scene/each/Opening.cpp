#include "../../../header/scene/each/Opening.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/renderer/define/ViewportDesc.h"
#include "../../../header/data/id/TEXTURE_ID.h"
Opening::Opening(GameDevice * _device)
	:m_device(_device),
	m_change(),
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
	if (m_lerp.isEnd()||m_device->input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Opening::draw(IRenderer * renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::ROGO);
	ViewportDesc view=renderer->getViewPort();
	desc.srcRect = GSrect(0, 0, view.width, view.height);
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
