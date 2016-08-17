#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
GamePlay::GamePlay(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_player()
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_IsEnd = false;
	m_player.initialize();
}

void GamePlay::update(float deltaTime)
{
	m_player.update(deltaTime);
}

void GamePlay::draw(const Renderer & renderer)
{
	m_player.draw(renderer);
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
