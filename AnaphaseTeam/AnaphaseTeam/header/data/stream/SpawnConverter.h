/**
* @file SpawnConverter.h
* @brief �����p�f�[�^�̃R���o�[�g�֐��I�u�W�F�N�g
* @author �����T��
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
