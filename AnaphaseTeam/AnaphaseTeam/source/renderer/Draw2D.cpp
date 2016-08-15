#include "../../header/renderer/Draw2D.h"
#include <sstream>
#include <iomanip>
Draw2D::Draw2D()
{
}

void Draw2D::textrueShadow(TEXTURE_ID id, const GSvector2 * _position, const GScolor * _color, const GSvector2 & offset) const
{
	GSvector2 shadowPos = *_position + offset;
	textrue(id, &shadowPos, &GScolor(0.0f, 0.0f, 0.0f, 0.8f));
	textrue(id, _position, _color);
}

void Draw2D::textrueShadow(TEXTURE_ID id, const GSvector2 * _position, const GSrect * _rect, const GScolor * _color, const GSvector2 & offset) const
{
	GSvector2 shadowPos = *_position + offset;
	textrue(id, &shadowPos, _rect, &GScolor(0.0f, 0.0f, 0.0f, 0.8f));

	textrue(id, _position, _rect, _color);
}

void Draw2D::textrue(TEXTURE_ID id, const GSvector2 * _position, const GScolor * _color) const
{
	gsDrawSprite2D(static_cast<GSuint>(id), _position, NULL, NULL, _color, NULL, NULL);
}

void Draw2D::textrue(TEXTURE_ID id, const GSvector2 * _position, const GSrect * _rect, const GScolor * _color) const
{
	gsDrawSprite2D(static_cast<GSuint>(id), _position, _rect, NULL, _color, NULL, NULL);
}

void Draw2D::textrue(TEXTURE_ID id, const GSvector2 * _position, const GSvector2 * _scaling, const GScolor * _color) const
{
	gsDrawSprite2D(static_cast<GSuint>(id), _position, NULL, NULL, _color, _scaling, NULL);
}

void Draw2D::textrue(TEXTURE_ID id, const GSvector2 * _position, const GSrect * _rect, const GSvector2 * _center, const GSvector2 * _scaling, GSfloat _rotation, const GScolor * _color) const
{
	gsDrawSprite2D(static_cast<GSuint>(id), _position, _rect, _center, _color, _scaling, _rotation);
}

void Draw2D::number(TEXTURE_ID id, const NumString & _number, const GSvector2 & _position, const GSvector2 & cuttingSize, const GScolor * _color) const
{
	GSvector2 pos = _position;
	for each (auto c in _number)
	{
		bool istoken = (c == '.');

		float x = istoken ? 10 : (c - '0');
		x *= cuttingSize.x;

		textrue(id, &pos, &GSrect(x, 0, x + cuttingSize.x, cuttingSize.y), _color);
		//位置をずらす .なら半分
		x = cuttingSize.x;
		x *= istoken ? 0.5f : 1.0f;
		pos.x += x;
	}
}

void Draw2D::number(TEXTURE_ID id, const GSvector2 & _position, const GSvector2 & cuttingSize, int point, const GScolor * _color) const
{
	GSvector2 pos = _position;
	for each (auto n in std::to_string(point))
	{
		float x = (n - '0') *cuttingSize.x;
		textrue(id, &pos, &GSrect(x, 0, x + cuttingSize.x, cuttingSize.y), _color);
		pos.x += cuttingSize.x;
	}
}

void Draw2D::number(TEXTURE_ID id, const GSvector2 & _position, const GSvector2 & cuttingSize, float point, unsigned int decimalNumber, unsigned int digitNumber, const GScolor * _color) const
{
	GSvector2 pos = _position;
	
	for each (auto c in transformToNumString(point, decimalNumber, digitNumber))
	{
		bool istoken = (c == '.');

		float x =istoken ? 10 : (c - '0');
		x *= cuttingSize.x;

		textrue(id, &pos, &GSrect(x, 0, x + cuttingSize.x, cuttingSize.y), _color);
		//位置をずらす .なら半分
		x = cuttingSize.x;
		x *= istoken ? 0.5f : 1.0f;
		pos.x += x;
	}
}

void Draw2D::numberShadow(TEXTURE_ID id, const GSvector2 & _position, const GSvector2 & cuttingSize, float point, unsigned int decimalNumber, unsigned int digitNumber, const GSvector2 & offset, const GScolor * _color) const
{
	number(id, _position + offset, cuttingSize, point, decimalNumber, digitNumber, &GScolor(0.0f, 0.0f, 0.0f, 0.8f));
	number(id, _position, cuttingSize, point, decimalNumber, digitNumber, _color);
}

void Draw2D::string(const std::string & text, const GSvector2 * _position, const GSuint size, const GScolor * _color, const GSbitfield & fontcode, const char * fontname) const
{
	gsFontParameter(fontcode, size, fontname);
	glColor4f(_color->r, _color->g, _color->b, _color->a);
	gsTextPos(_position->x, _position->y);
	gsDrawText(text.c_str());
}

void Draw2D::initBlend() const
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Draw2D::additionBlend() const
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

const NumString Draw2D::transformToNumString(float _number, GSuint _decimal, GSuint _digit) const
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(_decimal);

	//小数点を表示する場合は点の数も追加
	_digit += _decimal == 0 ? 0 : 1;
	//         0で埋める              　　　　　　　　　右寄せ
	stream << std::setfill('0') << std::setw(_digit) << std::right << _number;
	return stream.str();
}
