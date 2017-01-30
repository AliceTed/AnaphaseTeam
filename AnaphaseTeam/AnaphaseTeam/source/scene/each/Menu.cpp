#include "..\..\..\header\scene\each\Menu.h"
#include "renderer/IRenderer.h"
#include "device/GameDevice.h"
#include "data/id/BGM_ID.h"
#include "renderer/define/SpriteRenderDesc.h"

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
	case Select::STAFFROLL:
		//m_change.end(SceneMode::ENDING);
		m_change.end(SceneMode::RESULT);
		break;
	case Select::EXIT:
		m_change.end(SceneMode::TITLE);
		break;
	}
}
