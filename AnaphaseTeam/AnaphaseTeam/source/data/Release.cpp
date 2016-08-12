#include "../../header/data/Release.h"
#include "../../header/data/BGM_ID.h"
#include "../../header/data/SKELETON_ID.h"
#include "../../header/data/MESH_ID.h"
#include "../../header/data/OCTREE_ID.h"
#include "../../header/data/SE_ID.h"
#include "../../header/data/TEXTURE_ID.h"
#include "../../header/data/ANIMATION_ID.h"
#include <gslib.h>
namespace Data
{
	void Release::operator()(void)
	{
		deleteEach(gsDeleteTexture, TEXTURE_ID::SIZE);
		deleteEach(gsDeleteSE, SE_ID::SIZE);
		deleteEach(gsDeleteBGM, BGM_ID::SIZE);
		deleteEach(gsDeleteMesh, MESH_ID::SIZE);
		deleteEach(gsDeleteAnimation, ANIMATION_ID::SIZE);
		deleteEach(gsDeleteSkeleton, SKELETON_ID::SIZE);
		deleteEach(gsDeleteOctree, OCTREE_ID::SIZE);
	}
}