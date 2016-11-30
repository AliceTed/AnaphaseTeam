#pragma once
/**
* @file SoundLoader.h
* @brief Soundロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/12/01
*/
#include <string>
class SoundLoader
{
public:
	/**
	* @fn
	* @brief Soundロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_path) ファイルパス
	* @param (_extension) ファイルの拡張子
	*/
	void operator()(unsigned int _id, const std::string& _name, bool _isLoop = false, const std::string& _path = "./res/sound/", const std::string& _extension = ".wav");

	template<class ID>
	void operator()(ID _id, const std::string& _name, bool _isLoop = false, const std::string& _path = "./res/sound/", const std::string& _extension = ".wav")
	{
		(*this)(static_cast<unsigned int>(_id), _name,_isLoop, _path, _extension);
	}
};