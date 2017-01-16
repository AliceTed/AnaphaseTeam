#include "..\..\..\header\data\loader\ShaderLoader.h"
#include <gslib.h>
#include "data/Message.h"
void ShaderLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _vertex, const std::string & _flagment)
{
	std::string full_vertex = _path + _name + _vertex;
	std::string full_flagment= _path + _name + _flagment;
	if (!gsLoadShader(_id, full_vertex.c_str(), full_flagment.c_str()))
	{
		Message error;
		error("シェーダ―の読み込みエラー", full_vertex+":"+full_flagment);
	}
}
