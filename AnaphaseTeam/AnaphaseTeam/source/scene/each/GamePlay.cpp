#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/math/Random.h"
GamePlay::GamePlay(GameDevice* _device)
	:m_IsEnd(false),
	m_device(_device),
	m_Map(OCTREE_ID::ARENA),
	m_Camera(),
	m_cameracontroller(&m_Camera),
	m_enemys(),
	m_change(),
	m_lockon(_device),
	m_player(_device, &m_Camera, &m_lockon)
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

	m_player.initialize();
	//m_boss.initialize();
	m_enemys.initialize();
	Math::Random rnd;
	for (int i = 0; i < 2; i++)
	{
		Enemy* e = new Enemy(Transform(0, { 0,0,0 }, { rnd(-10.0f,10.0f),0,rnd(-10.0f,10.0f)}));
		m_enemys.add(e);
	}

	/*Boss boss;
	boss.initialize();*/
	m_lockon.addPlayer(&m_player);
}

void GamePlay::update(float deltaTime)
{
	m_player.collisionGround(m_Map);
	m_enemys.collisionGround(m_Map);
	//if ()return;
	m_change.update(deltaTime);
	// m_enemys;
	m_lockon.thinksEnemy(&m_enemys);
	m_lockon.nearEnemyFind(&m_enemys);
	m_player.update(deltaTime);
	m_enemys.update(deltaTime);
	m_enemys.collision(m_player);
	for (int i = 0; i < 2- m_enemys.size(); i++)
	{
		Math::Random rnd;
		Enemy* e = new Enemy(Transform(0, { 0,0,0 }, { rnd(-10.0f,10.0f),0,rnd(-10.0f,10.0f) }));
		m_enemys.add(e);
	}

	if (m_player.isDead())
	{
		m_change.end(SceneMode::ENDING);
	}
}

void GamePlay::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawSky(MESH_ID::SKY);
	
	//m_enemys[0].look_at(&m_cameracontroller, &m_player);
	m_lockon.look_at(&m_cameracontroller);
	m_cameracontroller.update();
	m_Map.draw(_renderer);
	m_enemys.draw(_renderer, m_Camera);
	m_player.draw(_renderer,m_Camera);	
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
