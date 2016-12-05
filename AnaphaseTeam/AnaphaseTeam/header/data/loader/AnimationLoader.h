#pragma once
/**
* @file MeshLoader.h
* @brief Animationロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/16
*/
#include <string>
class AnimationLoader
{
public:
	/**
	* @fn
	* @brief Animationロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/animation/", const std::string& _extension = ".anm");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/animation/", const std::string& _extension = ".anm")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};