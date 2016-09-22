#include "../../../header/scene/each/GamePlay.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
GamePlay::GamePlay(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Map(OCTREE_ID::KOUTEI),
	m_Camera(10,8,GSvector3(0,5,0)),
	actorManager(),
	m_player(_input)
{
}
GamePlay::~GamePlay()
{
}

void GamePlay::initialize()
{
	m_IsEnd = false;
	m_player.initialize();
}

void GamePlay::update(float deltaTime)
{
	m_player.update(deltaTime);
	m_player.collisionGround(m_Map);
}

void GamePlay::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawSky(MESH_ID::SKY);
	m_player.draw(_renderer,m_Camera);
	m_Map.draw(_renderer);
}

void GamePlay::finish()
{
}

const SceneMode GamePlay::next() const
{
	return SceneMode::ENDING;
}

const bool GamePlay::isEnd() const
{
	return false;
}

const bool GamePlay::isExit() const
{
	return false;
}
