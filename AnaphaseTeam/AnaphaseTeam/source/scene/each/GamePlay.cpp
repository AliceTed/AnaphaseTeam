#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/ui/UIManager.h"
#include "../../../header/data/id/MESH_ID.h"
#include "../../../header/stage/Phase.h"
GamePlay::GamePlay()
	:m_Map(OCTREE_ID::ARENA),
	m_Camera(&m_Map),
	m_cameracontroller(&m_Camera),
	m_change(),
	m_pause(m_change),//ポーズ
	m_actors(Transform(), &m_Camera)
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_change.initialize();
	m_change.begin(2);
	//ポーズ
	m_pause.initialize();
	m_actors.initialize();

	PhaseData data;
	data.m_octreeID = OCTREE_ID::ARENA;
	data.spawn = "spawn";
	m_phase = std::make_shared<Phase>(data);

	UIManager::getInstance();
}

void GamePlay::update(float deltaTime)
{
	m_pause.update(deltaTime);
	//ポーズ
	if (m_pause.isPause())
		return;
	
	m_actors.update(deltaTime);
	m_phase->update(deltaTime,m_actors);

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

	m_change.draw(_renderer);
	UIManager::getInstance().draw(_renderer);
	m_pause.draw(_renderer);

	m_phase->draw(_renderer);
}

void GamePlay::finish()
{
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
