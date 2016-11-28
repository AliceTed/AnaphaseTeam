#include "../../../header/data/stream/DataWriter.h"
#include <fstream>
const bool DataWriter::operator()(const std::vector<std::string>& _in, const std::string & _name, const std::string & _extension) const
{
	// �t�@�C���o�̓X�g���[���̏�����
	std::ofstream ofs(_name+ _extension);
	if (!ofs)return false;
	// �t�@�C����1�s����������
	for (auto& i: _in){ofs << i<< std::endl;}
	return true;
}
