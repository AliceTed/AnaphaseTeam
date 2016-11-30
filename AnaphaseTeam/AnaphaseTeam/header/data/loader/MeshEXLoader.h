#pragma once
/**
* @file MeshEXLoader.h
* @brief ���b�V��(shader��p)���[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/22
*/
#include <string>
class MeshEXLoader
{
public:
	/**
	* @fn
	* @brief MeshEx���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
	*/
	void operator ()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/mesh/", const std::string& _extension = ".msh");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/mesh/", const std::string& _extension = ".msh")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};