#pragma once
/**
* @file OctreeLoader.h
* @brief OctreeLoaderロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/23
*/
#include <string>
class OctreeLoader
{
public:
	/**
	* @fn
	* @brief Octreeロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_isShader)シェーダ専用か？
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator ()(unsigned int _id, const std::string& _name,bool _isShader=false,const std::string& _path = "./res/octree/", const std::string& _extension = ".oct");

	template<class ID>
	void operator()(ID _id, const std::string& _name, bool _isShader=false, const std::string& _path = "./res/octree/", const std::string& _extension = ".oct")
	{
		(*this)(static_cast<unsigned int>(_id), _name,_isShader,_path, _extension);
	}
private:
	/**
	* @fn
	* @brief Octreeロード
	* @param (_id) ResourceID
	* @param (_fullname) ファイルのフルパス
	* @param (_isShader)シェーダ専用か？
	* @return 読み込み成功か？
	*/
	const bool load(unsigned int _id, const std::string& _fullname, bool _isShader);
};