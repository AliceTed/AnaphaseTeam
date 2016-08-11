#include "../../../header/scene/each/GamePlay.h"

GamePlay::GamePlay()
	:m_IsEnd(false)
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_IsEnd = false;
}

void GamePlay::update(float deltaTime)
{
}

void GamePlay::draw(const Renderer & renderer)
{
}

void GamePlay::finish()
{
}

const SceneMode GamePlay::next() const
{
	return SceneMode();
}

const bool GamePlay::isEnd() const
{
	return false;
}
