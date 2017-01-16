#include "..\..\header\thread\LoadThread.h"
#include "../../header/data/loader/MeshLoader.h"
#include "../../header/data/loader/ModelLoader.h"
#include "../../header/data/loader/OctreeLoader.h"
#include "../../header/data/loader/ShaderLoader.h"
#include "../../header/data/loader/TextureLoader.h"
#include "../../header/data/loader/SoundLoader.h"
#include "../../header/data/loader/MyAnimationLoader.h"

#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/data/id/ANIMATION_ID.h"
#include "../../header/data/id/MESH_ID.h"
#include "../../header/data/id/Model_ID.h" 
#include "../../header/data/id/OCTREE_ID.h"
#include "../../header/data/id/SHADER_ID.h"
#include "../../header/data/id/BGM_ID.h"
#include "../../header/data/id/SE_ID.h"
#include "../../header/data/id/MYANIMATION_ID.h"
LoadThread::LoadThread()
	:m_isEnd(false), 
	m_section()
{
}

LoadThread::~LoadThread()
{
	end();
}

void LoadThread::run()
{
	//CriticalSection::Lock guard(m_section);
	while (true)
	{
		loadTextrue();
		//loadSound();
		loadModel();
		loadMyAnimation();
		break;
	}	
	end();
}

void LoadThread::end()
{
	m_isEnd = true;
	join();
}

const bool LoadThread::isEnd() const
{
	return m_isEnd;
}

void LoadThread::loadTextrue()
{
	TextureLoader tex;
	tex(TEXTURE_ID::WHITE, "white");
	tex(TEXTURE_ID::BLACK, "black");
	tex(TEXTURE_ID::EXIT, "TitleUI_EXIT");
	tex(TEXTURE_ID::OPTION, "TitleUI_OPTION");
	tex(TEXTURE_ID::GAMESTART, "TitleUI_START");
	tex(TEXTURE_ID::PRESSKEY, "TitleUI_PressKey");
	tex(TEXTURE_ID::CURSOR, "cursor");
	tex(TEXTURE_ID::TITLE_ROGO, "TitleRogo_Black");
	tex(TEXTURE_ID::CLEAR, "clear");
	tex(TEXTURE_ID::OPTION_BACKGROUND, "option_background");
	tex(TEXTURE_ID::PAD_A, "pad");
	tex(TEXTURE_ID::PAD_B, "pad");
	tex(TEXTURE_ID::ROGO, "rogo");
	tex(TEXTURE_ID::PLAYER_HP, "GameUI_HPGauge1");
	tex(TEXTURE_ID::PLAYER_HP_GAUGE, "GameUI_HPGauge2");
	tex(TEXTURE_ID::SPGAUGE, "GameUI_SPGauge2");


	tex(TEXTURE_ID::SPECIAL_MAIN, "special_main");
	tex(TEXTURE_ID::SPECIAL_ATTACK, "special_attack");
	tex(TEXTURE_ID::SPECIAL_RECOVERY, "special_recovery");
	tex(TEXTURE_ID::SPECIAL_SUPERARMOR, "special_superarmor");
	tex(TEXTURE_ID::GAMEOVER, "gameover");
	tex(TEXTURE_ID::PAUSE_GAMEBACK, "gameBack");
	tex(TEXTURE_ID::PAUSE_TITLEBACK, "titleBack");
	tex(TEXTURE_ID::STAFFROLL, "TitleUI_STAFF");
	tex(TEXTURE_ID::TITLE_MASK, "TitleRogo_Mask");
	tex(TEXTURE_ID::NUMBER, "number");
}

void LoadThread::loadSound()
{
	SoundLoader sound;
	sound(BGM_ID::TITLE, "titleBGM", true);
	sound(BGM_ID::GAMEPLAY, "gameplayBGM", true);
	sound(SE_ID::ENTER, "enter");
	sound(SE_ID::SELECT, "select");
	sound(SE_ID::PLAYER_ATTACK, "player_attack");
	sound(SE_ID::PLAYER_STEP, "player_step");
	sound(SE_ID::OPEN_SPECIALUI, "open_specialUI");
	sound(SE_ID::ENEMY_ATTACK, "enemy_attack");
}

void LoadThread::loadModel()
{
	/*ShaderLoader shader;
	shader(SHADER_ID::SKINNEDMESH, "skinned_mesh_bump");
	shader(SHADER_ID::OCTREE, "octree");*/
	//	shader(SHADER_ID::TEX_SONAR, "texture_soanr");
	ModelLoader model;
	MeshLoader mesh;
	model(MODEL_ID::PLAYER, "player/woman006");
	model(MODEL_ID::ENEMY, "enemy/ene1");

	mesh(MESH_ID::SKY, "sky/skydome");
	//meshïêäÌÅ@äô
	mesh(MESH_ID::WEAPON, "weapon/weapon");

	OctreeLoader oct;
	oct(OCTREE_ID::VISUAL, "map/map_limit");
	oct(OCTREE_ID::PHASE1, "map/map_collider1");
	oct(OCTREE_ID::PHASE2, "map/map_collider2");
	oct(OCTREE_ID::PHASE3, "map/map_collider3");
	oct(OCTREE_ID::PHASE4, "map/map_collider4");
}

void LoadThread::loadMyAnimation()
{
	MyAnimationLoader loader;
	loader(MYANIMATION_ID::SPECIAL_ATTACK_POP, "SpecialAttack_pop");
	loader(MYANIMATION_ID::SPECIAL_SUPERARMOR_POP, "SpecialsSuperArmor_pop");
	loader(MYANIMATION_ID::SPECIAL_RECOVERY_POP, "SpecialRecovery_pop");
	loader(MYANIMATION_ID::SPECIAL_ATTACK_BACK, "SpecialAttack_back");
	loader(MYANIMATION_ID::SPECIAL_SUPERARMOR_BACK, "SpecialsSuperArmor_back");
	loader(MYANIMATION_ID::SPECIAL_RECOVERY_BACK, "SpecialRecovery_back");
}
