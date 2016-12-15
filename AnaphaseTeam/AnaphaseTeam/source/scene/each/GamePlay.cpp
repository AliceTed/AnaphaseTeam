#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/math/Random.h"
#include "../../../header/ui/UIManager.h"
#include "../../../header/data/stream/SpawnReader.h"
GamePlay::GamePlay()
	:m_Map(OCTREE_ID::ARENA),
	m_Camera(&m_Map),
	m_cameracontroller(&m_Camera),
	m_enemys(),
	m_change(),
	m_lockon(),
	m_pause(m_change),//ポーズ
	m_player(&m_Camera, &m_lockon),
	m_spawnmanager()
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

	m_player.initialize();
	m_enemys.initialize();
	m_spawnmanager.initialize();

	SpawnReader spawnReader;
	spawnReader(&m_spawnmanager, "spawn");

	m_lockon.addPlayer(&m_player);
	UIManager::getInstance();
}

void GamePlay::update(float deltaTime)
{
	m_pause.update(deltaTime);
	//ポーズ
	if (m_pause.isPause())
		return;

	m_spawnmanager.update(deltaTime);
	if (m_spawnmanager.isCurrentEnd())
	{
		m_spawnmanager.createEnemy(m_enemys);
	}
	m_player.collisionGround(m_Map);
	m_enemys.collisionGround(m_Map);
	m_change.update(deltaTime);
	m_lockon.thinksEnemy(&m_enemys);
	m_player.targetFind(&m_enemys);
	m_player.update(deltaTime);
	m_enemys.update(deltaTime);
	m_enemys.collision(m_player);
	m_cameracontroller.update(deltaTime);

	if (m_player.isDead())
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
	m_lockon.look_at(&m_cameracontroller);
	m_cameracontroller.draw();
	_renderer->lookAt({ 0,0,0 }, { 0,0,0 }, { 0,0,0 });
	m_Map.draw(_renderer);
	m_enemys.draw(_renderer);
	m_player.draw(_renderer);
	m_change.draw(_renderer);
	UIManager::getInstance().draw(_renderer);
	m_pause.draw(_renderer);
}

void GamePlay::finish()
{
	m_player.finish();
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
