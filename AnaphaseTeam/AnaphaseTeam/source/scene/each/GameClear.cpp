#include "..\..\..\header\scene\each\GameClear.h"
#include "../../../header/device/GameDevice.h"
GameClear::GameClear(GameDevice* _device)
	:m_IsEnd(false),
	m_device(_device)
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
	if (m_device->input()->jump())
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
	return m_device->input()->exit();
}
