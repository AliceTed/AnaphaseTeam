#include "../../../header/scene/each/GameOver.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
GameOver::GameOver(const Input * _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_change()
{
}

GameOver::~GameOver()
{
}

void GameOver::initialize()
{
	m_IsEnd = false;
	m_change.initialize();
	m_change.begin();
}

void GameOver::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	if (m_Input->isJoyTriggerA())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void GameOver::draw(const Renderer & _renderer)
{
	_renderer.getDraw2D().textrue(TEXTURE_ID::TITLE_ROGO, &GSvector2(0, 0));
	m_change.draw(_renderer);
}

void GameOver::finish()
{
}

const SceneMode GameOver::next() const
{
	return m_change.next();
}

const bool GameOver::isEnd() const
{
	return m_change.isEnd();
}

const bool GameOver::isExit() const
{
	return false;
}
