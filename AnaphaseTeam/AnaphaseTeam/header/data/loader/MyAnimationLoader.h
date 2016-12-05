#pragma once
/**
* @file MyAnimationLoader.h
* @brief ����A�j���[�V�������[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/12/02
*/
#include <string>
class MyAnimation;
class MyAnimationLoader
{
public:
	/**
	* @fn
	* @brief ����A�j���[�V�������[�h�p
	* @param (_id) ResourceID 
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
	*/
	void operator()(unsigned int _id, const std::string& _name,const std::string& _path="./res/myanimation/",const std::string& _extension = ".myanim");

	template<class ID>
	void operator()(ID _id, const std::string& _name, const std::string& _path = "./res/myanimation/", const std::string& _extension = ".myanim")
	{
		(*this)(static_cast<unsigned int>(_id),_name,_path,_extension);
	}

};