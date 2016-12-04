#include "..\..\..\header\scene\each\Menu.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/data/id/BGM_ID.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"

Menu::Menu()
	:m_IsExit(false),
	m_menu(),
	m_change()
{
}

Menu::~Menu()
{
}

void Menu::initialize()
{
	m_IsExit = false;
	m_change.initialize();
	m_change.begin();
	m_menu.initialize();
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
}

void Menu::update(float deltaTime)
{
	GameDevice::getInstacnce().sound().bgmFade(BGM_ID::TITLE, deltaTime * 0.01f);
	m_menu.update(deltaTime);
	if (m_change.update(deltaTime))return;
	m_menu.operation(*this);
}

void Menu::draw(IRenderer * _renderer)
{
	m_menu.draw(_renderer);
	m_change.draw(_renderer);
}

void Menu::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::TITLE);
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENTER);
	m_menu.finish();
}

const SceneMode Menu::next() const
{
	return m_change.next();
}

const bool Menu::isEnd() const
{
	return m_change.isEnd();
}

const bool Menu::isExit() const
{
	return m_IsExit;
}
void Menu::decision(Select _select)
{
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	switch (_select)
	{
	case Select::GAMESTART:
		m_change.end(SceneMode::GAMEPLAY);
		break;
	case Select::OPTION:
		m_change.end(SceneMode::OPTION);
		break;
	case Select::EXIT:
		m_IsExit = true;
		break;
	}
}
