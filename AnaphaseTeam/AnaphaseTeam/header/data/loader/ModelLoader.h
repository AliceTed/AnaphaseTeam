#pragma once
/**
* @file ModelLoader.h
* @brief Model(アニメーション、スケルトン、メッシュ)ロード用関数オブジェクト
* @author 松尾裕也
* @date 2016/11/22
*/
#include <string>
class ModelLoader
{
public:
	/**
	* @fn
	* @brief Modelロード用
	* @param (_id) ResourceID
	* @param (_name) ファイル名
	* @param (_isShader)シェーダ専用か？
	* @param (_path) ファイルパス
	*/
	void operator()(unsigned int _id, const std::string& _name,bool _isShader=true,const std::string& _path = "./res/model/");
	template<class ID>
	void operator()(ID _id, const std::string& _name, bool _isShader = true, const std::string& _path = "./res/model/")
	{
		(*this)(static_cast<unsigned int>(_id), _name,_isShader,_path);
	}
};