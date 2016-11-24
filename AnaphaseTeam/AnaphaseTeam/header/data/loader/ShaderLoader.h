#pragma once
/**
* @file ShaderLoader.h
* @brief ShaderLoader���[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/16
*/
#include <string>
class ShaderLoader
{
public:
	/**
	* @fn
	* @brief ShaderLoader���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_vertex) �o�[�e�b�N�Xshader�p�t�@�C���̊g���q
	* @param (_flagment) �t���O�����gshader�p�t�@�C���̊g���q
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/shader/", const std::string& _vertex = ".glslv", const std::string& _flagment = ".glslf");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/shader/", const std::string& _vertex = ".glslv", const std::string& _flagment = ".glslf")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _vertex,_flagment);
	}
};