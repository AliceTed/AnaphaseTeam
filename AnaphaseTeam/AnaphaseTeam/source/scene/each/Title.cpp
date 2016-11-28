#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/data/BGM_ID.h"
Title::Title()
	:m_IsExit(false),
	m_title(),
	m_change()
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
	m_title.initialize();
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
}
void Title::update(float deltaTime)
{
	GameDevice::getInstacnce().sound().bgmFade(BGM_ID::TITLE, deltaTime * 0.01f);

	if (m_change.update(deltaTime))return;
	m_title.update(deltaTime, *this);
}

void Title::draw(const Renderer & renderer)
{
	m_title.draw(renderer);
	m_change.draw(renderer);
}

void Title::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::TITLE);
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENTER);
	m_title.finish();
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
	return m_IsExit;
}
void Title::decision(Select _select)
{
	if (!GameDevice::getInstacnce().input()->jump())return;
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
void Title::select(SelectUI & _select)
{
	if (GameDevice::getInstacnce().input()->up())
	{
		_select.previous();
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		_select.next();
		GameDevice::getInstacnce().sound().playSE(SE_ID::SELECT);
	}
	GameDevice::getInstacnce().sound().stopSE(SE_ID::SELECT);
}
