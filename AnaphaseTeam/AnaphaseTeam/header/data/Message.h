#pragma once
/**
* @file Message.h
* @brief MessageBox 関数オブジェクト
* @author 松尾裕也
* @date 2016/11/16
*/
#include <string>
class Message
{
public:
	void operator ()(const std::string& _title, const std::string& _message);
};