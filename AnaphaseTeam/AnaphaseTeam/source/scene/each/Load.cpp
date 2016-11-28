#include "../../../header/scene/each/Load.h"
#include "../../../header/data/Loader.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/sound/Sound.h"

#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/data/MESH_ID.h"
#include "../../../header/data/Model_ID.h" 
#include "../../../header/data/SE_ID.h"
#include "../../../header/data/BGM_ID.h"
Load::Load(Sound* _sound)
	:m_IsEnd(false),
	m_sound(_sound)
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
	return SceneMode::OPENING;
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
	tex(TEXTURE_ID::WHITE, "white");
	tex(TEXTURE_ID::BLACK, "black");
	tex(TEXTURE_ID::EXIT, "Exit");
	tex(TEXTURE_ID::OPTION, "option");
	tex(TEXTURE_ID::GAMESTART, "GameStart");
	tex(TEXTURE_ID::CURSOR, "cursor");
	tex(TEXTURE_ID::TITLE_ROGO, "title_rogo");
	tex(TEXTURE_ID::CLEAR, "clear");
	tex(TEXTURE_ID::OPTION_BACKGROUND, "option_background");
	tex(TEXTURE_ID::PAD_A, "pad");
	tex(TEXTURE_ID::PAD_B, "pad");
	tex(TEXTURE_ID::ROGO, "rogo");
	tex(TEXTURE_ID::SP_UI, "UI_SP");
	tex(TEXTURE_ID::SP_UI1, "UI_SP_1");
	tex(TEXTURE_ID::SP_UI2, "UI_SP_2");
	tex(TEXTURE_ID::SP_UI3, "UI_SP_3");
}
void Load::loadSound()
{
	//Data::LoadSE loadse;
	//loadse(SE_ID::TITLE,"down",2);

	//Data::LoadBGM loadbgm;
	//loadbgm(BGM_ID::TITLE, "a");

	m_sound->loadSE(SE_ID::TITLE, "down");
	m_sound->loadBGM(BGM_ID::TITLE, "Tulip");
}

void Load::loadModel()
{
	using namespace Data;
	LoadMesh mesh;
	LoadModel model;
	model(MODEL_ID::PLAYER, "player/woman003");
	model(MODEL_ID::ENEMY, "enemy/skeleton");

	mesh(MESH_ID::SKY, "sky/skydome");
	//meshïêäÌÅ@äô
	mesh(MESH_ID::WEAPON, "weapon/weapon");
	LoadOctree oct;
	oct(OCTREE_ID::ARENA, "arena");
}
