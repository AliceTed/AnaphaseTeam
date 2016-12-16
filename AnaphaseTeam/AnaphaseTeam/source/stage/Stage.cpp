#include "..\..\header\stage\Stage.h"
#include "../../header/stage/Phase.h"
#include "../../header/data/id/MESH_ID.h"
#include "../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../header/ui/UIManager.h"
#include "../../header/device/GameDevice.h"
Stage::Stage(const Transform & _init)
	:m_Map(OCTREE_ID::VISUAL),
	m_cameracontroller(),
	m_actors(_init, m_cameracontroller.get_camera()),
	m_pahsemanager()
{
}

void Stage::initialize()
{
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
}

void Stage::update(float deltaTime)
{
	m_actors.update(deltaTime);
	m_pahsemanager.update(deltaTime, m_actors, m_cameracontroller);
	m_cameracontroller.update(deltaTime);
	UIManager::getInstance().update(deltaTime);
}

void Stage::draw(IRenderer * _renderer)
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
}

void Stage::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::GAMEPLAY);
	m_actors.finish();
}

const bool Stage::isClear() const
{
	return m_pahsemanager.isEnd();
}

const bool Stage::isDead() const
{
	return m_actors.isPlayerDead();
}