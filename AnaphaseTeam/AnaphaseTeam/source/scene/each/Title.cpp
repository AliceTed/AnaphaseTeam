#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
#include "../../../header/sound/Sound.h"
#include "../../../header/data/SE_ID.h"
#include "../../../header/data/BGM_ID.h"

Title::Title(const Input* _input, const Sound* _sound)
	:m_Input(_input),
	m_Sound(_sound),
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
	//m_Sound->playBGM(BGM_ID::TITLE);
	
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
	m_Sound->stopSE(SE_ID::TITLE);
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
	if (!m_Input->jumpTrigger())return;
	switch (_select)
	{
	case Select::GAMESTART:
		m_change.end(SceneMode::GAMEPLAY);
		break;
	case Select::OPTION:
		m_change.end(SceneMode::TITLE);
		break;
	case Select::EXIT:
		m_IsExit = true;
		break;
	}
}
void Title::select(SelectUI & _select)
{
	if (m_Input->up())
	{
		m_Sound->playSE(SE_ID::TITLE);
		_select.previous();
	}
	if (m_Input->down())
	{
		m_Sound->playSE(SE_ID::TITLE);
		_select.next();
	}
}
