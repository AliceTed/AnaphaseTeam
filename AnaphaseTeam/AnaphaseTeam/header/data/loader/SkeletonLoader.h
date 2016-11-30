#pragma once
/**
* @file SkeletonLoader.h
* @brief �X�P���g���̃��[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/16
*/
#include <string>
class SkeletonLoader
{
public:
	/**
	* @fn
	* @brief �X�P���g�����[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
	*/
	void operator()(unsigned int _id, const std::string& _name, const std::string& _path = "./res/skeleton/", const std::string& _extension = ".skl");
	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/skeleton/", const std::string& _extension = ".skl")
	{
		(*this)(static_cast<unsigned int>(_id), _name, _path, _extension);
	}
};