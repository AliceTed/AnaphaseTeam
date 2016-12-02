#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/math/Random.h"

GamePlay::GamePlay()
	:m_Map(OCTREE_ID::ARENA),
	m_Camera(),
	m_cameracontroller(&m_Camera),
	m_enemys(),
	m_change(),
	m_lockon(),
	m_player(&m_Camera, &m_lockon),
	test1(TEXTURE_ID::SPECIAL_ATTACK,MYANIMATION_ID::SPECIAL_ATTACK,GScolor(1,0,0,1)),
	test2( TEXTURE_ID::SPECIAL_SUPERARMOR,MYANIMATION_ID::SPECIAL_SUPERARMOR, GScolor(1, 0, 0, 1)),
	test3(TEXTURE_ID::SPECIAL_RECOVERY,MYANIMATION_ID::SPECIAL_RECOVERY, GScolor(1, 0, 0, 1))
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_change.initialize();
	m_change.begin(2);

	m_player.initialize();
	m_enemys.initialize();
	Math::Random rnd;
	for (int i = 0; i < 2; i++)
	{
		Enemy* e = new Enemy(Transform(0, { 0,0,0 }, { rnd(-10.0f,10.0f),0,rnd(-10.0f,10.0f)}));
		m_enemys.add(e);
	}

	m_lockon.addPlayer(&m_player);
}

void GamePlay::update(float deltaTime)
{
	if (gsGetKeyTrigger(GKEY_F))
	{
		test1.start();
		test2.start();
		test3.start();
	}
	if (gsGetKeyTrigger(GKEY_G))
	{
		test1.rev();
		test2.rev();
		test3.rev();
	}
	m_player.collisionGround(m_Map);
	m_enemys.collisionGround(m_Map);
	m_change.update(deltaTime);
	m_lockon.thinksEnemy(&m_enemys);
	m_lockon.nearEnemyFind(&m_enemys);
	m_player.update(deltaTime);
	m_enemys.update(deltaTime);
	m_enemys.collision(m_player);
	m_cameracontroller.update(deltaTime);
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

	test1.update(deltaTime);
	test2.update(deltaTime);
	test3.update(deltaTime);
}
#include "../../../header/renderer/define/SpriteRenderDesc.h"
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

	test1.draw(_renderer, GSvector2(500, 300));
	test2.draw(_renderer,GSvector2(500, 300));
	test3.draw(_renderer, GSvector2(500, 300));

	SpriteRenderDesc s;
	s.matrix.translate(GSvector2(460, 265));
	s.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_MAIN);
	_renderer->render(s);
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
