#pragma once
/**
* @file SkeletonLoader.h
* @brief スケルトンのロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/16
*/
#include <string>
class SkeletonLoader
{
public:
	/**
	* @fn
	* @brief スケルトンロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/skeleton/", const std::string& _extension = ".skl");
	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/skeleton/", const std::string& _extension = ".skl")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};