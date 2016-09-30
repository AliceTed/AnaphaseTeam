#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"

Title::Title(const Input* _input)
	:m_Input(_input),
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
		_select.previous();
	}
	if (m_Input->down())
	{
		_select.next();
	}
}
