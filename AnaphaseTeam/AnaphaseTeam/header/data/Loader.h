#pragma once
#ifndef _LOADER_H_
#define _LOADER_H_
/**
* @file Loader.h
* @brief リソース管理
* @author 松尾裕也
* @date 2016/8/02
*/

#include <string>
#include <gslib.h>

#include "PathConnect.h"
#include "CastID.h"
#include "LoadError.h"
namespace Data
{
	class LoadSE
	{
	public:
		/*
		同時再生最大数 max,再生モード flag
		GWAVE_WAIT 他の再生中ウェイト
		GWAVE_LOOP ループ再生
		GWAVE_DEFAULT
		*/
		template<class ID>
		void operator ()(ID id, const std::string& name, int max, GWAVEFLAG flag = GWAVE_DEFAULT, const std::string& path = "./res/sound/", const std::string& extension = ".wav");
	};
	class LoadBGM
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/sound/", const std::string& extension = ".mds");
	};
	class LoadMesh
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/model/", const std::string& extension = ".msh");
	};
	class LoadSkeleton
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/model/", const std::string& extension = ".skl");
	};
	class LoadAnimation
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/model/", const std::string& extension = ".anm");
	};
	class LoadOctree
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/model/", const std::string& extension = ".oct");
	};
	class LoadTexture
	{
	public:
		template<class ID>
		void operator ()(ID id, const std::string& name, const std::string& path = "./res/texture/", const std::string& extension = ".png");
	};
}
template<class ID>
void Data::LoadSE::operator()(ID _id, const std::string & name, int max, GWAVEFLAG flag, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadSE(cast(_id), connect(name, path, extension).c_str(), max, flag), [&name] { ErrorMessage mes; mes(name, "SE");});
}
template<class ID>
void Data::LoadBGM::operator()(ID _id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadBGM(cast(_id), connect(name, path, extension).c_str(), GMIDI_LOOP), [&name] { ErrorMessage mes; mes(name, "BGM");});
}
template<class ID>
void Data::LoadMesh::operator()(ID id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadMesh(cast(id), connect(name, path, extension).c_str()), [&name] { ErrorMessage mes; mes(name, "Mesh");});
}
template<class ID>
void Data::LoadSkeleton::operator()(ID id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadSkeleton(cast(id), connect(name, path, extension).c_str()), [&name] { ErrorMessage mes; mes(name, "Skeleton");});
}
template<class ID>
void Data::LoadAnimation::operator()(ID id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadAnimation(cast(id), connect(name, path, extension).c_str()), [&name] { ErrorMessage mes; mes(name, "Animation");});
}
template<class ID>
void Data::LoadOctree::operator()(ID id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadOctree(cast(id), connect(name, path, extension).c_str()), [&name] { ErrorMessage mes; mes(name, "Octree");});
}
template<class ID>
void Data::LoadTexture::operator()(ID id, const std::string & name, const std::string & path, const std::string & extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadTexture(cast(id), connect(name, path, extension).c_str()),[&] { ErrorMessage mes; mes(name, "Texture");});
}
#endif