#pragma once
/**
* @file OctreeLoader.h
* @brief OctreeLoader���[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/23
*/
#include <string>
class OctreeLoader
{
public:
	/**
	* @fn
	* @brief Octree���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_isShader)�V�F�[�_��p���H
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
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
	* @brief Octree���[�h
	* @param (_id) ResourceID
	* @param (_fullname) �t�@�C���̃t���p�X
	* @param (_isShader)�V�F�[�_��p���H
	* @return �ǂݍ��ݐ������H
	*/
	const bool load(unsigned int _id, const std::string& _fullname, bool _isShader);
};