#pragma once
/**
* @file ModelLoader.h
* @brief Model(�A�j���[�V�����A�X�P���g���A���b�V��)���[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/22
*/
#include <string>
class ModelLoader
{
public:
	/**
	* @fn
	* @brief Model���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_isShader)�V�F�[�_��p���H
	* @param (_path) �t�@�C���p�X
	*/
	void operator()(unsigned int _id, const std::string& _name,bool _isShader=true,const std::string& _path = "./res/model/");
	template<class ID>
	void operator()(ID _id, const std::string& _name, bool _isShader = true, const std::string& _path = "./res/model/")
	{
		(*this)(static_cast<unsigned int>(_id), _name,_isShader,_path);
	}
};