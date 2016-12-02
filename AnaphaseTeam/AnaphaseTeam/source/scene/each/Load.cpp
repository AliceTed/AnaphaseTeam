#include "../../../header/scene/each/Load.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/data/loader/MeshLoader.h"
#include "../../../header/data/loader/ModelLoader.h"
#include "../../../header/data/loader/OctreeLoader.h"
#include "../../../header/data/loader/ShaderLoader.h"
#include "../../../header/data/loader/TextureLoader.h"
#include "../../../header/data/loader/SoundLoader.h"
#include "../../../header/data/loader/MyAnimationLoader.h"

#include "../../../header/data/id/TEXTURE_ID.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/data/id/MESH_ID.h"
#include "../../../header/data/id/Model_ID.h" 
#include "../../../header/data/id/OCTREE_ID.h"
#include "../../../header/data/id/SHADER_ID.h"
#include "../../../header/data/id/BGM_ID.h"
#include "../../../header/data/id/SE_ID.h"
#include "../../../header/data/id/MYANIMATION_ID.h"
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
	loadMyAnimation();
	m_IsEnd = true;
}
void Load::draw(IRenderer * renderer)
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
	TextureLoader tex;
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

	tex(TEXTURE_ID::SPECIAL_MAIN, "special_main");
	tex(TEXTURE_ID::SPECIAL_ATTACK, "special_attack");
	tex(TEXTURE_ID::SPECIAL_RECOVERY, "special_recovery");
	tex(TEXTURE_ID::SPECIAL_SUPERARMOR, "special_superarmor");
}
void Load::loadSound()
{
	SoundLoader sound;
	sound(BGM_ID::TITLE, "Tulip");
	sound(SE_ID::ENTER,"enter");
	sound(SE_ID::SELECT, "select");
}

void Load::loadModel()
{
	ShaderLoader shader;
	shader(SHADER_ID::SKINNEDMESH,"skinned_mesh_bump");

	ModelLoader model;
	MeshLoader mesh;
	model(MODEL_ID::PLAYER, "player/woman003");
	model(MODEL_ID::ENEMY, "enemy/skeleton");

	mesh(MESH_ID::SKY, "sky/skydome");
	//meshïêäÌÅ@äô
	mesh(MESH_ID::WEAPON, "weapon/weapon");

	OctreeLoader oct;
	oct(OCTREE_ID::ARENA, "arena");
}

void Load::loadMyAnimation()
{
	MyAnimationLoader loader;
	loader(MYANIMATION_ID::SPECIAL_ATTACK,"SpecialAttack_pop");
	loader(MYANIMATION_ID::SPECIAL_SUPERARMOR, "SpecialsSuperArmor_pop");
	loader(MYANIMATION_ID::SPECIAL_RECOVERY, "SpecialRecovery_pop");
}
