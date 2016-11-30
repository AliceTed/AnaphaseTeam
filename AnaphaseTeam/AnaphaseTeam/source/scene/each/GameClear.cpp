#include "..\..\..\header\scene\each\GameClear.h"
#include "../../../header/device/GameDevice.h"
GameClear::GameClear()
	:m_IsEnd(false)
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
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_IsEnd = true;
	}
}

void GameClear::draw(IRenderer * renderer)
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
	return GameDevice::getInstacnce().input()->exit();
}
