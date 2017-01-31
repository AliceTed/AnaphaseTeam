#include "scene/each/Title.h"
#include "device/GameDevice.h"
#include "renderer/IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "device/GameDevice.h"
#include "data/id/BGM_ID.h"
#include "data/id/SHADER_ID.h"
Title::Title()
	:m_IsExit(false),
	m_change(),
	m_pressKey(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), Flash::Param(0.05f)),
	m_time(0.0f)
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
	m_time = 0.0f;
}
void Title::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	m_time += _deltaTime;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::MENU);
		GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	}
	m_pressKey.update(_deltaTime);
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

