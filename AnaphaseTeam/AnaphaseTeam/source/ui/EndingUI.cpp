#include "..\..\header\ui\EndingUI.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/device/GameDevice.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

EndingUI::EndingUI()
	:m_credit(TEXTURE_ID::STAFFROLL, GSvector2(450, 720),Flash::Param(0.5f, 1.0f, 1)),// 1.0f),
	m_still(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), Flash::Param(0.05f, 0.0f, 1)),//0.0f)
	m_staffRoll()
{
}

EndingUI::~EndingUI()
{
}

void EndingUI::initilize()
{
	m_credit.initilize();
	m_still.initilize();
	m_staffRoll.initilize();
}

void EndingUI::update(float deltatime)
{
	m_credit.update(deltatime);
	m_still.update(deltatime);
}

void EndingUI::draw(IRenderer* _renderer)
{
	m_credit.draw(_renderer);
	m_still.draw(_renderer);
	m_staffRoll.draw(_renderer);
}

