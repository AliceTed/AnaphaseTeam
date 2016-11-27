#include "../../../header/data/stream/DataWriter.h"
#include <fstream>
const bool DataWriter::operator()(const std::vector<std::string>& _in, const std::string & _name, const std::string & _extension) const
{
	// ファイル出力ストリームの初期化
	std::ofstream ofs(_name+ _extension);
	if (!ofs)return false;
	// ファイルに1行ずつ書き込み
	for (auto& i: _in){ofs << i<< std::endl;}
	return true;
}
