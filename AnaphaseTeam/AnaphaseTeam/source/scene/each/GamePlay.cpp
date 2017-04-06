#include "scene/each/GamePlay.h"
#include "renderer/IRenderer.h"
#include "device/GameDevice.h"
#include "stage/Stage.h"
#include "stage/StageData.h"
#include "data/stream/StageReader.h"

#include "../header/data/id/RENDER_TARGET_ID.h"
#include "../header/data/id/SHADER_ID.h"
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
	m_stage.reset();
	m_stage = nullptr;
	m_stage = std::make_unique<Stage>(data);

}

void GamePlay::update(float deltaTime)
{
	//ポーズ
	if (!m_pause.isPause())
	{
		m_stage->update(deltaTime);
		m_change.update(deltaTime);
		endingScene();
	}
	m_pause.update(deltaTime);
	//チートコマンド（ゲームプレイ初期化）
	if (gsGetKeyTrigger(GKEY_2))
	{
		initialize();
	}
}

void GamePlay::draw(IRenderer * _renderer)
{
	m_stage->draw(_renderer);
	m_change.draw(_renderer);
	m_pause.draw(_renderer);
/*	gsBeginRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BASE));
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	m_stage->draw(_renderer);
	m_change.draw(_renderer);
	m_pause.draw(_renderer);

	gsEndRenderTarget();

	//光度抽出 brightに書き込む
	gsBeginRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BRIGHT));
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gsBeginShader(static_cast<GSuint>(SHADER_ID::BRIGHT));
	glActiveTexture(GL_TEXTURE0);
	gsBindRenderTargetTexture(static_cast<GSuint>(RENDER_TARGET_ID::BASE), 0);
	gsSetShaderParamTexture("u_sceneColor", 0);
	gsSetShaderParam1f("u_minBright", 0.5f);
	gsDrawRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BASE));
	gsEndShader();
	gsEndRenderTarget();

	//抽出した光度にブラーをかける　
	gsBeginRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BLOOM_BLUR));
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gsBeginShader(static_cast<GSuint>(SHADER_ID::BLOOM_BLUR));
	glActiveTexture(GL_TEXTURE0);
	gsBindRenderTargetTexture(static_cast<GSuint>(RENDER_TARGET_ID::BRIGHT), 0);
	gsSetShaderParamTexture("u_sceneColor", 0);
	gsSetShaderParam2f("u_direction", &GSvector2(1, 0.0f));
	gsDrawRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BASE));
	gsEndShader();
	gsEndRenderTarget();

	//デフォルトとブラーをかけたものを合成
	gsBeginRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BLOOM));
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gsBeginShader(static_cast<GSuint>(SHADER_ID::BLOOM));
	glActiveTexture(GL_TEXTURE0);
	gsBindRenderTargetTexture(static_cast<GSuint>(RENDER_TARGET_ID::BASE), 0);
	glActiveTexture(GL_TEXTURE1);
	gsBindRenderTargetTexture(static_cast<GSuint>(RENDER_TARGET_ID::BLOOM_BLUR), 0);
	gsSetShaderParamTexture("u_sceneColor", 0);
	gsSetShaderParamTexture("u_bloomColor", 1);
	gsSetShaderParam1f("u_toneScale", 0.8f);
	gsDrawRenderTarget(static_cast<GSuint>(RENDER_TARGET_ID::BASE));
	gsEndShader();
	gsEndRenderTarget();

	gsUnindRenderTargetTexture(static_cast<GSuint>(RENDER_TARGET_ID::BLOOM_BLUR), 0);

	GSuint bloom = static_cast<GSuint>(RENDER_TARGET_ID::BLOOM);
	glActiveTexture(GL_TEXTURE0);
	gsBindRenderTargetTexture(bloom, 0);
	gsDrawRenderTarget(bloom);

	gsUnindRenderTargetTexture(bloom, 0);
	*/
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

void GamePlay::endingScene()
{
	if (m_stage->isDead())
	{
		m_change.end(SceneMode::GAMEOVER);
		return;
	}
	if (!m_stage->isClear())
	{
		return;
	}
	m_change.end(SceneMode::RESULT);
}
