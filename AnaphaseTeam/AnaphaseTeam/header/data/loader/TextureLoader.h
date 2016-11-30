#pragma once
/**
* @file TextureLoader.h
* @brief テクスチャのロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/16
*/
#include <string>
class TextureLoader
{
public:
	/**
	* @fn
	* @brief Textureロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/texture/", const std::string& _extension = ".png");
	
	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/texture/", const std::string& _extension = ".png")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};