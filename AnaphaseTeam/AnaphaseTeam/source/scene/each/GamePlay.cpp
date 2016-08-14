#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
GamePlay::GamePlay(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input)
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
	return SceneMode::ENDING;
}

const bool GamePlay::isEnd() const
{
	return false;
}
