#include "../../../header/scene/each/Load.h"
#include "../../../header/data/Loader.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/data/ANIMATION_ID.h"
#include "../../../header/data/MESH_ID.h"
#include "../../../header/data/SKELETON_ID.h"
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

void Load::loadTextrue()
{
	Data::LoadTexture loadTex;
	//loadTex(TEXTURE_ID::TEST,"test");
	//loadTex(TEXTURE_ID::SIZE, "eee");
}
void Load::loadSound()
{
	Data::LoadSE loadse;
	//loadse(SE_ID::SIZE,"bbb",2);

	Data::LoadBGM loadbgm;
	/*loadbgm(BGM_ID::SIZE, "bbb");*/
}

void Load::loadModel()
{
	using namespace Data;
	LoadMesh mesh;
	LoadAnimation anim;
	LoadSkeleton skl;
	//LoadOctree oct;
	mesh(MESH_ID::KARATE,"karate");
	anim(ANIMATION_ID::KARATE, "karate");
	skl(SKELETON_ID::KARATE,"karate");
	//oct(OCTREE_ID::SIZE, "ooo");
}
