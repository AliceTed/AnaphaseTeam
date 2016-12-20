#include "..\..\header\stage\Stage.h"
#include "../../header/stage/Phase.h"
#include "../../header/data/id/MESH_ID.h"
#include "../../header/renderer/define/SkyBoxRenderDesc.h"
#include "../../header/ui/UIManager.h"
#include "../../header/device/GameDevice.h"
#include "../../header/stage/StageData.h"
#include "../../header/data/stream/PhaseReader.h"
#include "../../header/camera/CameraWork/E_CameraWorkID.h"
Stage::Stage(const StageData& _stage)
	:m_Map(OCTREE_ID::VISUAL),
	m_cameracontroller(),
	m_actors(_stage.init, m_cameracontroller.get_camera()),
	m_phaseManage()
{
	m_actors.initialize();

	PhaseReader reader;
	for (auto& i:_stage.pahseData)
	{
		PhaseData data;
		reader(&data,i);
		m_phaseManage.add(new Phase(data));
	}
	m_phaseManage.changeFirst();

	m_cameracontroller.change_cameraWork(E_CameraWorkID::EVENT);
}
Stage::~Stage()
{
	finish();
}
void Stage::update(float deltaTime)
{
	m_actors.update(deltaTime);
	m_phaseManage.update(deltaTime, m_actors, m_cameracontroller);
	m_cameracontroller.update(deltaTime);
	UIManager::getInstance().update(deltaTime);
}

void Stage::draw(IRenderer * _renderer)
{
	SkyBoxRenderDesc desc;
	desc.meshID = static_cast<unsigned int>(MESH_ID::SKY);
	_renderer->render(desc);
	m_actors.lockAt(&m_cameracontroller);
	m_cameracontroller.draw(_renderer);

	_renderer->lookAt({ 0,0,0 }, { 0,0,0 }, { 0,0,0 });
	m_Map.draw(_renderer);
	m_actors.draw(_renderer);
	m_phaseManage.draw(_renderer);
	UIManager::getInstance().draw(_renderer);
}

void Stage::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::GAMEPLAY);
	m_actors.finish();
}

const bool Stage::isClear() const
{
	return m_phaseManage.isEnd();
}

const bool Stage::isDead() const
{
	return m_actors.isPlayerDead();
}