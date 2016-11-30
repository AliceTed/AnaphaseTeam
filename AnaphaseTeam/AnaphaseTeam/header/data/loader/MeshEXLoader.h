#pragma once
/**
* @file MeshEXLoader.h
* @brief メッシュ(shader専用)ロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/22
*/
#include <string>
class MeshEXLoader
{
public:
	/**
	* @fn
	* @brief MeshExロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator ()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/mesh/", const std::string& _extension = ".msh");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/mesh/", const std::string& _extension = ".msh")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};