#include "..\..\..\header\scene\each\GameClear.h"
#include "../../../header/device/Input.h"

GameClear::GameClear(const Input * _input)
	:m_IsEnd(false),
	m_Input(_input)
{
}

GameClear::~GameClear()
{
}

void GameClear::initialize()
{
	m_IsEnd = false;
}

void GameClear::update(float deltaTime)
{
	if (m_Input->isJoyTriggerA())
	{
		m_IsEnd = true;
	}
}

void GameClear::draw(const Renderer & renderer)
{
}

void GameClear::finish()
{
}

const SceneMode GameClear::next() const
{
	return SceneMode::TITLE;
}

const bool GameClear::isEnd() const
{
	return m_IsEnd;
}

const bool GameClear::isExit() const
{
	return m_Input->exit();
}
