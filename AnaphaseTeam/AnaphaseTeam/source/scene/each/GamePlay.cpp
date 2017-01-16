#include "scene/each/GamePlay.h"
#include "renderer/IRenderer.h"
#include "device/GameDevice.h"
#include "stage/Stage.h"
#include "stage/StageData.h"
#include "data/stream/StageReader.h"
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

	StageData data;
	StageReader reader;
	reader(&data, "stage");
	m_stage = std::make_unique<Stage>(data);
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
