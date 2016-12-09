#include "../../../header/scene/each/Title.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/data/id/BGM_ID.h"
Title::Title()
	:m_IsExit(false),
	m_change(),
	m_pressKey(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), 1.0f)
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsExit = false;
	m_change.initialize();
	m_change.begin();
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
	m_pressKey.initilize();
}
void Title::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::MENU);
		GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	}
	m_pressKey.flashing(0.7f);
}

void Title::draw(IRenderer * _renderer)
{
	SpriteRenderDesc tatle;
	tatle.textureID = static_cast<GSuint>(TEXTURE_ID::TITLE_ROGO);
	_renderer->render(tatle);

	m_pressKey.draw(_renderer);
	m_change.draw(_renderer);
}

void Title::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::TITLE);
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENTER);
}

const SceneMode Title::next() const
{
	return m_change.next();
}

const bool Title::isEnd() const
{
	return m_change.isEnd();
}

const bool Title::isExit() const
{
	return false;
}
	
