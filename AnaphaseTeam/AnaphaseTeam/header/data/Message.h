#pragma once
/**
* @file Message.h
* @brief MessageBox �֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/11/16
*/
#include <string>
class Message
{
public:
	void operator ()(const std::string& _title, const std::string& _message);
};