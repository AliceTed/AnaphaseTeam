#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/renderer/define/ViewportDesc.h"
#include "../../../header/data/id/TEXTURE_ID.h"
Ending::Ending(GameDevice* _device)
	:m_IsEnd(false),
	m_device(_device),
	m_change()
{
}
Ending::~Ending()
{
}

void Ending::initialize()
{
	m_IsEnd = false;
	m_change.initialize();
	m_change.begin();
}

void Ending::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	//Œˆ’èƒ{ƒ^ƒ“ì‚Á‚Ä‚à‚¢‚¢‚©‚à
	if (m_device->input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Ending::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::CLEAR);
	ViewportDesc view = _renderer->getViewPort();
	desc.srcRect = GSrect(0, 0, view.width, view.height);
	desc.matrix.setTranslation(170, 90, 0);
	_renderer->render(desc);

	m_change.draw(_renderer);
}

void Ending::finish()
{
}

const SceneMode Ending::next() const
{
	return m_change.next();
}

const bool Ending::isEnd() const
{
	return m_change.isEnd();
}

const bool Ending::isExit() const
{
	return false;
}
