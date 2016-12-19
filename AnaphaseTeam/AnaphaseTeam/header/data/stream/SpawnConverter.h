/**
* @file SpawnConverter.h
* @brief 生成用データのコンバート関数オブジェクト
* @author 松尾裕也
* @date 2016/12/14
*/
#pragma once
#include <string>
#include "../json/Picojson.h"
struct SpawnData;
class SpawnConverter
{
public:
	const bool operator()(SpawnData* _out,picojson::object& _data)const;
};
