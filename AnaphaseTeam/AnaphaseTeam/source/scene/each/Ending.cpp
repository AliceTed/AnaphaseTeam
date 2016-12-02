#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/data/id/TEXTURE_ID.h"
Ending::Ending()
	:m_IsEnd(false),
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
	//決定ボタン作ってもいいかも
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Ending::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::GAMEOVER);
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
