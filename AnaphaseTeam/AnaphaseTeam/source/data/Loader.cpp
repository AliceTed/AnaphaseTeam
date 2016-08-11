#include "../../header/data/Loader.h"
#include "../../header/data/CastID.h"
#include "../../header/data/LoadError.h"
namespace Data
{
	void LoadSE::operator()(SE_ID id, const std::string & name, int max, GWAVEFLAG flag, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadSE(cast(id), fullpath.c_str(), max, flag), [&name] { ErrorMessage mes; mes(name, "SE");});
	}
	void LoadBGM::operator()(BGM_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadBGM(cast(id), fullpath.c_str(), GMIDI_LOOP), [&name] { ErrorMessage mes; mes(name, "BGM");});
	}

	void LoadMesh::operator()(MESH_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadMesh(cast(id), fullpath.c_str()), [&name] { ErrorMessage mes; mes(name, "Mesh");});
	}

	void LoadSkeleton::operator()(SKELETON_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadSkeleton(cast(id), fullpath.c_str()), [&name] { ErrorMessage mes; mes(name, "Skeleton");});
	}

	void LoadAnimation::operator()(ANIMATION_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadAnimation(cast(id), fullpath.c_str()), [&name] { ErrorMessage mes; mes(name, "Animation");});
	}

	void LoadOctree::operator()(OCTREE_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadOctree(cast(id), fullpath.c_str()), [&name] { ErrorMessage mes; mes(name, "Octree");});
	}

	void LoadTexture::operator()(TEXTURE_ID id, const std::string & name, const std::string & path, const std::string & extension)
	{
		std::string fullpath = path + name + extension;
		LoadError error;
		CastID cast;
		error(gsLoadTexture(cast(id), fullpath.c_str()), [&name] { ErrorMessage mes; mes(name, "Texture");});
	}
}