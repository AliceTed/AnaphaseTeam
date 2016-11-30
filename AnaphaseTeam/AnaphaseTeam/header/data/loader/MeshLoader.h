#pragma once
/**
* @file MeshLoader.h
* @brief ���b�V�����[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/16
*/
#include <string>
class MeshLoader
{
public:
	/**
	* @fn
	* @brief Mesh���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
	*/
	void operator ()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/model/", const std::string& _extension = ".msh");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/model/", const std::string& _extension = ".msh")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};