#pragma once
/**
* @file MyAnimationLoader.h
* @brief 自作アニメーションロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/12/02
*/
#include <string>
class MyAnimation;
class MyAnimationLoader
{
public:
	/**
	* @fn
	* @brief 自作アニメーションロード用
	* @param (_id) ResourceID 
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name,const std::string& _path="./res/myanimation/",const std::string& _extension = ".myanim");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/myanimation/", const std::string& _extension = ".myanim")
	{
		(*this)(static_cast<unsigned int>(_id),_name,_path,_extension);
	}

};