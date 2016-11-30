#pragma once
/**
* @file SoundLoader.h
* @brief Sound���[�h�p�֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/12/01
*/
#include <string>
class SoundLoader
{
public:
	/**
	* @fn
	* @brief Sound���[�h�p
	* @param (_id) ResourceID
	* @param (_name) �t�@�C����
	* @param (_path) �t�@�C���p�X
	* @param (_extension) �t�@�C���̊g���q
	*/
	void operator()(unsigned int _id, const std::string& _name, bool _isLoop = false, const std::string& _path = "./res/sound/", const std::string& _extension = ".wav");

	template<class ID>
	void operator()(ID _id, const std::string& _name, bool _isLoop = false, const std::string& _path = "./res/sound/", const std::string& _extension = ".wav")
	{
		(*this)(static_cast<unsigned int>(_id), _name,_isLoop, _path, _extension);
	}
};