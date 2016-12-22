#include "../../header/ui/TitleUI.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/scene/each/Menu.h"
#include "../../header/device/GameDevice.h"
TitleUI::TitleUI()
	:m_select(),
	m_fade(TEXTURE_ID::BLACK)
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::initialize()
{
	createSelect();
	m_fade.initialize();
	//m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 1.0f), 0);
}

void TitleUI::update(float deltaTime)
{
	m_select.update(deltaTime);
	m_fade.update(deltaTime);
}

void TitleUI::draw(IRenderer* _renderer)
{
	m_fade.draw(_renderer);
	m_select.draw(_renderer);
}

void TitleUI::finish()
{
	m_select.initialize();
}
void TitleUI::operation(Menu& _menu)
{
	if (m_fade.isStart())
	{
		return;
	}

	if (!m_select.isStart())
	{
		return;
	}

	if (GameDevice::getInstacnce().input()->up())
	{
		m_select.previous();
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		m_select.next();
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
	}
	if (GameDevice::getInstacnce().input()->jump())
	{
		_menu.decision(m_select.currentSelect());
		m_select.startMove();
		//m_select.slowMove();
		m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 0.0f), 1.3f);
	}
}
void TitleUI::createSelect()
{
	m_select.initialize();

	ScaleImage imageStart(TEXTURE_ID::GAMESTART, GSvector2(0, 90), false, 465.0f, 0.0f);
	m_select.add(Select::GAMESTART, imageStart);

	ScaleImage imageOption(TEXTURE_ID::OPTION, GSvector2(0, 210), false, 460.0f, 0.0f);
	m_select.add(Select::OPTION, imageOption);

	ScaleImage imageStaff(TEXTURE_ID::STAFFROLL, GSvector2(0, 335), false, 390.0f, 0.0f);
	m_select.add(Select::STAFFROLL, imageStaff);

	ScaleImage imageExit(TEXTURE_ID::EXIT, GSvector2(0, 610), false, 470.0f, 0.0f);
	m_select.add(Select::EXIT, imageExit);

	m_select.startChange();

}
