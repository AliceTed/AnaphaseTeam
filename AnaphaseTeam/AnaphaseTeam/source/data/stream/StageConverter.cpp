#include "..\..\..\header\data\stream\StageConverter.h"
#include "stage/StageData.h"
#include <iterator>
const bool StageConverter::operator()(StageData * _out, picojson::value & _value) const
{
	picojson::object parent = _value.get<picojson::object>();
	if (parent.count("Stage") == 0)return false;
	picojson::value obj =parent["Stage"];
	//Phase�����I�u�W�F�N�g���擾
	picojson::object stage = obj.get<picojson::object>();
	
	if (stage.count("Position") ==0)return false;
	//position�z��
	picojson::array p_array =stage["Position"].get<picojson::array>();
	GSvector3 pos;
	for (unsigned int i=0;i<p_array.size();i++)
	{
		pos.v[i] = static_cast<float>(p_array[i].get<double>());
	}
	if (stage.count("Angle") == 0)return false;
	float angle = stage["Angle"].get<double>();
	//�t�F�[�Y�t�@�C���̖��O���擾
	if (stage.count("PhaseFile") == 0)return false;
	picojson::array data = stage["PhaseFile"].get<picojson::array>();
	std::vector<std::string> files;
	files.clear();
	for (auto& i:data)
	{
		files.emplace_back(i.get<std::string>());
	}

	_out->init = Transform(angle, { 0.0f,1.0f,0.0f },pos);
	_out->pahseData.clear();
	std::copy(files.begin(), files.end(), std::back_inserter(_out->pahseData));
	return true;
}
