#pragma once
/**
* @file ShaderLoader.h
* @brief ShaderLoaderロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/16
*/
#include <string>
class ShaderLoader
{
public:
	/**
	* @fn
	* @brief ShaderLoaderロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_vertex) バーテックスshader用ファイルの拡張子
	* @param (_flagment) フラグメントshader用ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/shader/", const std::string& _vertex = ".glslv", const std::string& _flagment = ".glslf");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/shader/", const std::string& _vertex = ".glslv", const std::string& _flagment = ".glslf")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _vertex,_flagment);
	}
};