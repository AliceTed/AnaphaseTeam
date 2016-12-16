#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/ui/UIManager.h"
#include "../../../header/data/id/MESH_ID.h"
#include "../../../header/stage/Phase.h"

GamePlay::GamePlay()
	:m_Map(OCTREE_ID::VISUAL),
	m_cameracontroller(),
	m_change(),
	m_pause(m_change),//ポーズ
	m_actors(Transform({ 0,0,0 }, { 115.0f,1.2f,-7 }), m_cameracontroller.get_camera()),
	m_pahsemanager()
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
	m_actors.initialize();

	PhaseData data;
	data.octreeID = OCTREE_ID::PHASE1;
	data.spawn = "spawn";

	m_pahsemanager.add(new Phase(data));
	PhaseData data2;
	data2.octreeID = OCTREE_ID::PHASE2;
	data2.spawn = "spawn2";

	m_pahsemanager.add(new Phase(data2));

	PhaseData data3;
	data3.octreeID = OCTREE_ID::PHASE3;
	data3.spawn = "spawn3";
	m_pahsemanager.add(new Phase(data3));
	m_pahsemanager.changeFirst();

	UIManager::getInstance();
}

void GamePlay::update(float deltaTime)
{
	m_pause.update(deltaTime);
	//ポーズ
	if (m_pause.isPause())
		return;

	m_actors.update(deltaTime);
	m_pahsemanager.update(deltaTime,m_actors,m_cameracontroller);

	m_change.update(deltaTime);
	m_cameracontroller.update(deltaTime);
	
	
	if (m_actors.isPlayerDead())
	{
		m_change.end(SceneMode::ENDING);
	}
	UIManager::getInstance().update(deltaTime);
}

void GamePlay::draw(IRenderer * _renderer)
{
	SkyBoxRenderDesc desc;
	desc.meshID = static_cast<unsigned int>(MESH_ID::SKY);
	_renderer->render(desc);
	m_actors.lockAt(&m_cameracontroller);
	m_cameracontroller.draw();

	_renderer->lookAt({ 0,0,0 }, { 0,0,0 }, { 0,0,0 });
	m_Map.draw(_renderer);
	m_actors.draw(_renderer);
	m_pahsemanager.draw(_renderer);
	UIManager::getInstance().draw(_renderer);
	m_change.draw(_renderer);
	m_pause.draw(_renderer);
}

void GamePlay::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::GAMEPLAY);
	m_actors.finish();
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
