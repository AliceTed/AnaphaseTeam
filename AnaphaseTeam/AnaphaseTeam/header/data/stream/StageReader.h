#pragma once

/*
JSON読み込み部分がほぼ同じなので後で変える
リファクタ対象
*/
#include <string>
struct StageData;
class StageReader
{
public:
	void operator()(StageData* _out, const std::string& _name, const std::string& _path = "./res/data/", const std::string& _extension = ".JSON")const;
private:
	const bool load(StageData* _out, const std::string& _file)const;
};
