#include "scene/each/Title.h"
#include "device/GameDevice.h"
#include "renderer/IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "device/GameDevice.h"
#include "data/id/BGM_ID.h"
#include "data/id/SHADER_ID.h"
#include "effect\EffectManager.h"
#include "data\id\EFFECT_ID.h"
Title::Title()
	:m_IsExit(false),
	m_change(),
	m_pressKey(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), 1.0f),
	m_time(0.0f)
{
}

Title::~Title()
{
}

void Title::initialize()
{
	EffectManager::getInstance().effectPlay(EFFECT_ID::TITLE_BACK, GSvector3(0,0,0));
	m_IsExit = false;
	m_change.initialize();
	m_change.begin();
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
	m_pressKey.initilize();	
	m_time = 0.0f;
	
}
void Title::update(float _deltaTime)
{
	EffectManager::getInstance().update();	
	if (m_change.update(_deltaTime))return;
	m_time += _deltaTime;	
	
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::MENU);
		GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	}
	m_pressKey.flashing(0.7f);
}
void Title::draw(IRenderer * _renderer)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		5, 0, 10,
		5, 0, 0
		, 0, 1, 0);

	EffectManager::getInstance().draw();

	SpriteRenderDesc tatle;
	tatle.textureID = static_cast<GSuint>(TEXTURE_ID::TITLE_ROGO);
	_renderer->render(tatle);

	m_pressKey.draw(_renderer);
	m_change.draw(_renderer);
}

void Title::finish()
{
	EffectManager::getInstance().stopAll();
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

