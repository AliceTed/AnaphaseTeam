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
		void operator ()(ID _id, const std::string& _name, int _max, GWAVEFLAG _flag = GWAVE_DEFAULT, const std::string& _path = "./res/sound/", const std::string& _extension = ".wav");
	};
	class LoadBGM
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/sound/", const std::string& _extension = ".mds");
	};
	class LoadMesh
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/model/", const std::string& _extension = ".msh");
	};
	class LoadSkeleton
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/model/", const std::string& _extension = ".skl");
	};
	class LoadAnimation
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/model/", const std::string& _extension = ".anm");
	};
	class LoadOctree
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/octree/", const std::string& _extension = ".oct");
	};
	class LoadTexture
	{
	public:
		template<class ID>
		void operator ()(ID _id, const std::string& _name, const std::string& _path = "./res/texture/", const std::string& _extension = ".png");
	};

	class LoadModel
	{
	public:
		/**
		* @fn
		* @brief モデル用ロード関数
		* @param (_id) 管理ID
		* @param (_name) モデル名
		* @param (_path) モデルのデータがあるパス
		* @detail .mshと.anmと.sklの三つのデータをロードする
		*/
		template<class ID>
		void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/model/");
	};
}
template<class ID>
void Data::LoadSE::operator()(ID _id, const std::string & _name, int _max, GWAVEFLAG _flag, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadSE(cast(_id), connect(_name, _path, _extension).c_str(), _max, _flag), [&_name] { ErrorMessage mes; mes(_name, "SE");});
}
template<class ID>
void Data::LoadBGM::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadBGM(cast(_id), connect(_name, _path, _extension).c_str(), GMIDI_LOOP), [&_name] { ErrorMessage mes; mes(_name, "BGM");});
}
template<class ID>
void Data::LoadMesh::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadMesh(cast(_id), connect(_name, _path, _extension).c_str()), [&_name] { ErrorMessage mes; mes(_name, "Mesh");});
}
template<class ID>
void Data::LoadSkeleton::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadSkeleton(cast(_id), connect(_name, _path, _extension).c_str()), [&_name] { ErrorMessage mes; mes(_name, "Skeleton");});
}
template<class ID>
void Data::LoadAnimation::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadAnimation(cast(_id), connect(_name, _path, _extension).c_str()), [&_name] { ErrorMessage mes; mes(_name, "Animation");});
}
template<class ID>
void Data::LoadOctree::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadOctree(cast(_id), connect(_name, _path, _extension).c_str()), [&_name] { ErrorMessage mes; mes(_name, "Octree");});
}
template<class ID>
void Data::LoadTexture::operator()(ID _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	LoadError error;
	CastID cast;
	PathConnect connect;
	error(!!gsLoadTexture(cast(_id), connect(_name, _path, _extension).c_str()),[&] { ErrorMessage mes; mes(_name, "Texture");});
}
template<class ID>
void Data::LoadModel::operator()(ID _id, const std::string & _name, const std::string & _path)
{
	LoadMesh mesh;
	LoadAnimation anim;
	LoadSkeleton skl;

	mesh(_id,_name,_path);
	anim(_id, _name, _path);
	skl(_id, _name, _path);
}

#endif