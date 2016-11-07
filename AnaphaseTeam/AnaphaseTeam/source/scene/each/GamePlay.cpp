#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
GamePlay::GamePlay(GameDevice* _device)
	:m_IsEnd(false),
	m_device(_device),
	m_Map(OCTREE_ID::KOUTEI),
	m_Camera(10,8,GSvector3(0,5,0)),
	m_cameracontroller(&m_Camera),
	actorManager(),
	m_player(_device,&m_Camera),
	m_boss(),
	m_change()
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_change.initialize();
	m_change.begin(2);
	m_IsEnd = false;

	collision.initialize();
	m_player.initialize();
	m_boss.initialize();
	m_player.addCollisionGroup(&collision);
	m_boss.addCollisionGroup(&collision);
}

void GamePlay::update(float deltaTime)
{
	m_player.collisionGround(m_Map);
	m_boss.collisionGround(m_Map);
	if (m_change.update(deltaTime))return;
	
	m_player.update(deltaTime);
	m_boss.update(deltaTime);

	collision.update(deltaTime);

	/*if (m_device->input()->reset())
	{
		m_change.end(SceneMode::GAMEPLAY);
	}*/

	//if (m_Input->isJoyTriggerY())
	//{
	//	m_change.end(SceneMode::ENDING);
	//}
}

void GamePlay::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawSky(MESH_ID::SKY);
	m_boss.look_at(&m_cameracontroller, &m_player);
	m_player.draw(_renderer,m_Camera);
	m_Map.draw(_renderer);
	m_boss.draw(_renderer, m_Camera);
	collision.draw(_renderer);
	m_change.draw(_renderer);
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
