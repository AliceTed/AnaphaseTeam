/**
* @file Pause.cpp
* @brief ポーズクラスソースファイル
* @author Hisaaki
* @date 2016/12/05
*/
#include "../../../header/scene/each/Pause.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/scene/SceneChange.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/define/StringRenderDesc.h" 
#include "../../../header/renderer/define/SpriteRenderDesc.h" 

static const GSvector2 ICONPOSITION[2] = { GSvector2(450,350),GSvector2(450,550) };

Pause::Pause(SceneChange& _change) :
	m_currentSelect(0), m_isPause(false), m_change(_change)
{}
Pause::~Pause()
{}
void Pause::initialize()
{
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
}
void Pause::draw(IRenderer* _renderer)
{
	if (!m_isPause)return;
	
	//背景
	SpriteRenderDesc backDesc;
	backDesc.textureID = static_cast<GSuint>(TEXTURE_ID::BLACK);
	backDesc.color = GScolor4(1, 1, 1, 0.4f);
	_renderer->render(backDesc);


	//ゲームに戻る
	SpriteRenderDesc desc; GSmatrix4 mat;
	mat.identity();
	mat.translate(500, 300, 0);
	desc.matrix = mat;
	desc.color = GScolor4(1, 1, 1, 1);
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::PAUSE_GAMEBACK);
	_renderer->render(desc);

	//タイトルへ戻る
	SpriteRenderDesc desc2;
	GSmatrix4 mat2;
	mat2.identity();
	mat2.translate(500, 500, 0);
	desc2.matrix = mat2;
	desc2.textureID = static_cast<GSuint>(TEXTURE_ID::PAUSE_TITLEBACK);
	_renderer->render(desc2);

	//アイコン
	SpriteRenderDesc iconDesc;
	GSmatrix4 iconMat;
	iconMat.identity();
	iconMat.translate(ICONPOSITION[m_currentSelect]);	
	iconDesc.matrix = iconMat;
	iconDesc.textureID = static_cast<GSuint>(TEXTURE_ID::CURSOR);
	iconDesc.color = GScolor4(1, 1, 1, 1);
	_renderer->render(iconDesc);
}
void Pause::finish()
{

}
void Pause::select()
{
	if (GameDevice::getInstacnce().input()->up())
	{
		m_currentSelect += 1;
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		m_currentSelect -= 1;
	}
	clamp();
}
void Pause::decision()
{
	if (!GameDevice::getInstacnce().input()->decision())return;
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