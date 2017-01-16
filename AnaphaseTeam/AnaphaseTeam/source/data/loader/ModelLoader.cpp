#include "..\..\..\header\data\loader\ModelLoader.h"
#include "data/loader/AnimationLoader.h"
#include "data/loader/MeshLoader.h"
#include "data/loader/MeshEXLoader.h"
#include "data/loader/SkeletonLoader.h"
void ModelLoader::operator()(unsigned int _id, const std::string & _name, bool isShader, const std::string & _path)
{
	AnimationLoader animation;
	animation(_id,_name,_path);

	SkeletonLoader skeleton;
	skeleton(_id, _name, _path);

	if (isShader)
	{
		MeshEXLoader mesh;
		mesh(_id, _name, _path);
		return;
	}
	MeshLoader mesh;
	mesh(_id, _name, _path);
}

