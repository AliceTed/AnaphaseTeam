#pragma once
#ifndef _LOADER_H_
#define _LOADER_H_
/**
* @file Loader.h
* @brief リソース管理
* @author 松尾裕也
* @date 2016/8/02
*/
#include "BGM_ID.h"
#include "SKELETON_ID.h"
#include "MESH_ID.h"
#include "OCTREE_ID.h"
#include "SE_ID.h"
#include "TEXTURE_ID.h"
#include "ANIMATION_ID.h"
#include <string>
#include <gslib.h>

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
		void operator ()(SE_ID id, const std::string& name, int max, GWAVEFLAG flag = GWAVE_DEFAULT, const std::string& path = "./res/sound/", const std::string& extension = ".wav");
	};
	class LoadBGM
	{
	public:
		void operator ()(BGM_ID id, const std::string& name, const std::string& path = "./res/sound/", const std::string& extension = ".mds");
	};
	class LoadMesh
	{
	public:
		void operator ()(MESH_ID id, const std::string& name, const std::string& path = "res/model/", const std::string& extension = ".msh");
	};
	class LoadSkeleton
	{
	public:
		void operator ()(SKELETON_ID id, const std::string& name, const std::string& path = "res/model/", const std::string& extension = ".skl");
	};
	class LoadAnimation
	{
	public:
		void operator ()(ANIMATION_ID id, const std::string& name, const std::string& path = "res/model/", const std::string& extension = ".anm");
	};
	class LoadOctree
	{
	public:
		void operator ()(OCTREE_ID id, const std::string& name, const std::string& path = "res/model/", const std::string& extension = ".oct");
	};
	class LoadTexture
	{
	public:
		void operator ()(TEXTURE_ID id, const std::string& name, const std::string& path = "res/texture/", const std::string& extension = ".png");
	};
}
#endif