/**
* @file Pause.cpp
* @brief ポーズクラスソースファイル
* @author Hisaaki
* @date 2016/12/05
*/
#include "scene/each/Pause.h"
#include "renderer/IRenderer.h"
#include "scene/SceneChange.h"
#include "device/GameDevice.h"
#include "renderer/define/StringRenderDesc.h" 
#include "renderer/define/SpriteRenderDesc.h" 
//!アイコンの位置
static const GSvector2 ICONPOSITION[2] = { GSvector2(450,350),GSvector2(450,550) };

Pause::Pause(SceneChange& _change) :
	m_currentSelect(0), m_isPause(false),
	m_change(_change),
	m_image()
{}
Pause::~Pause()
{}
void Pause::initialize()
{
	m_image.initialize();
	m_currentSelect = 0;
}
void Pause::update(float deltatime)
{
	if (gsGetJoyTrigger(0, GJOY_BUTTON_8))
	{
		m_isPause = !m_isPause;
		initialize();
	}

	if (!m_isPause)return;
	select();
	decision();
	m_image.update(deltatime);
}
void Pause::draw(IRenderer* _renderer)
{
	if (!m_isPause)return;

	SpriteRenderDesc desc;
	//背景
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::BLACK);
	desc.color = GScolor4(1, 1, 1, 0.4f);
	_renderer->render(desc);
	//選択肢
	m_image.draw(_renderer);
}
void Pause::finish()
{
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENTER);
	GameDevice::getInstacnce().sound().stopSE(SE_ID::SELECT);
}
void Pause::select()
{
	bool isselect = false;
	if (GameDevice::getInstacnce().input()->up())
	{
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
		m_currentSelect += 1;
		isselect = true;
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
		m_currentSelect -= 1;
		isselect = true;
	}
	clamp();
	if (isselect)m_image.start(m_currentSelect);
}
void Pause::decision()
{
	if (!GameDevice::getInstacnce().input()->decision())return;
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	if (m_currentSelect == 0) { initialize(); }
	if (m_currentSelect == 1) { m_change.end(SceneMode::TITLE); }
	m_isPause = false;
}
bool Pause::isPause()
{
	return m_isPause;
}
void Pause::clamp()
{
	if (m_currentSelect > 1)m_currentSelect = 0;
	if (m_currentSelect < 0)m_currentSelect = 1;
}