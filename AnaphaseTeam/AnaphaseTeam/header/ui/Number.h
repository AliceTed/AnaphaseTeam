#pragma once
#include "../data/id/TEXTURE_ID.h"

#include <gslib.h>
#include <string>
#include <sstream>

class IRenderer;
class Number
{
public:
	Number(TEXTURE_ID _id,const GSvector2& _position);
	~Number();
	std::string intToString(int _number);
	void draw(IRenderer * _renderer, int _nunber);
private:
	TEXTURE_ID m_id;
	GSvector2 m_position;
	int m_nunber;
};