#include "../../../header/scene/each/Load.h"
#include "../../../header/data/Loader.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/data/MESH_ID.h"
#include "../../../header/data/SKELETON_ID.h"
#include "../../../header/data/Model_ID.h" 
#include "../../../header/data/SE_ID.h"
#include "../../../header/data/BGM_ID.h"
Load::Load()
	:m_IsEnd(false)
{
}
Load::~Load()
{

}
void Load::initialize()
{
	m_IsEnd = false;
}

void Load::update(float deltaTime)
{
	loadTextrue();
	loadSound();
	loadModel();
	m_IsEnd = true;
}
void Load::draw(const Renderer & renderer)
{
}

void Load::finish()
{
}

const SceneMode Load::next() const
{
	return SceneMode::TITLE;
}

const bool Load::isEnd() const
{
	return m_IsEnd;
}

const bool Load::isExit() const
{
	return false;
}

void Load::loadTextrue()
{
	Data::LoadTexture tex;
	tex(TEXTURE_ID::BLACK, "black");
	tex(TEXTURE_ID::EXIT, "Exit");
	tex(TEXTURE_ID::OPTION, "option");
	tex(TEXTURE_ID::GAMESTART, "GameStart");
	tex(TEXTURE_ID::CURSOR, "cursor");
	tex(TEXTURE_ID::TITLE_ROGO, "title_rogo");
}
void Load::loadSound()
{
	Data::LoadSE loadse;
	loadse(SE_ID::TITLE,"down",2);

	Data::LoadBGM loadbgm;
	//loadbgm(BGM_ID::TITLE, "title");
}

void Load::loadModel()
{
	using namespace Data;
	LoadMesh mesh;
	LoadModel model;
	model(MODEL_ID::PLAYER,"kendo" );
	model(MODEL_ID::BOSS, "boss/bos3");

	mesh(MESH_ID::SKY, "sky/skydome");
	LoadOctree oct;
	oct(OCTREE_ID::KOUTEI, "koutei");
}
