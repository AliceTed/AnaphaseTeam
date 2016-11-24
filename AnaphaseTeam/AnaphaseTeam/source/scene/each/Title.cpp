#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
//#include "../../../header/data/BGM_ID.h"
Title::Title(GameDevice* _device)
	:m_device(_device),
	m_IsExit(false),
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
}
void Title::update(float deltaTime)
{
	m_device->sound().playBGM(BGM_ID::TITLE);
	if (m_change.update(deltaTime))return;
	m_title.update(deltaTime, *this);
}

void Title::draw(IRenderer * renderer)
{
	m_title.draw(renderer);
	m_change.draw(renderer);
}

void Title::finish()
{
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
	if (!m_device->input()->jump())return;
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
	if (m_device->input()->up())
	{
		_select.previous();
	}
	if (m_device->input()->down())
	{
		_select.next();
	}
}
