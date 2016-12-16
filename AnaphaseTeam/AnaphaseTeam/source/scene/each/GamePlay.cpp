#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/stage/Stage.h"
GamePlay::GamePlay()
	:m_change(),
	m_pause(m_change),//ポーズ
	m_stage(nullptr)
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::GAMEPLAY);
	GameDevice::getInstacnce().sound().bgmVolume(BGM_ID::GAMEPLAY, 0.8f);

	m_change.initialize();
	m_change.begin(2);
	//ポーズ
	m_pause.initialize();
	m_stage = std::make_unique<Stage>(Transform({ 0,0,0 }, { 115.0f,1.2f,-7 }));
	m_stage->initialize();
}

void GamePlay::update(float deltaTime)
{
	m_pause.update(deltaTime);
	//ポーズ
	if (m_pause.isPause())
		return;
	m_stage->update(deltaTime);
	m_change.update(deltaTime);
	if (m_stage->isClear()||m_stage->isDead())
	{
		m_change.end(SceneMode::ENDING);
	}
}

void GamePlay::draw(IRenderer * _renderer)
{
	m_stage->draw(_renderer);
	m_change.draw(_renderer);
	m_pause.draw(_renderer);
}

void GamePlay::finish()
{
	m_stage->finish();
	m_stage.reset();
	m_stage = nullptr;
}

const SceneMode GamePlay::next() const
{
	return m_change.next();
}

const bool GamePlay::isEnd() const
{
	return m_change.isEnd();
}

const bool GamePlay::isExit() const
{
	return false;
}
