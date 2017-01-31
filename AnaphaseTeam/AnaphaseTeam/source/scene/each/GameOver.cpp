#include "../header/scene/each/GameOver.h"
#include "renderer/IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "device/GameDevice.h"
#include "data/id/TEXTURE_ID.h"

GameOver::GameOver()
	:m_change(),
	m_pressKey(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), Flash::Param(0.05f))
{
}

GameOver::~GameOver()
{
}

void GameOver::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_pressKey.initilize();
}

void GameOver::update(float _deltaTime)
{
	if (m_change.update(_deltaTime)) return;
	m_pressKey.update(_deltaTime);
	change();
}

void GameOver::draw(IRenderer * _renderer)
{

	SpriteRenderDesc gameover;
	gameover.textureID = static_cast<GSuint>(TEXTURE_ID::GAMEOVER);
	_renderer->render(gameover);
	m_pressKey.draw(_renderer);
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

void GameOver::count()
{
}

void GameOver::change()
{
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::ENDING);
	}
}
