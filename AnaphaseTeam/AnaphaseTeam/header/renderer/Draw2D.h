#pragma once
#ifndef _DRAW2D_H_
#define _DRAW2D_H_
#include <gslib.h>
#include <string>
#include "../data/TEXTURE_ID.h"
class Draw2D
{
public:
	Draw2D();
	void textrueShadow(TEXTURE_ID id, const GSvector2* _position, const GScolor* _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f), const GSvector2& offset = GSvector2(4.0f, 4.0f))const;
	void textrueShadow(TEXTURE_ID id, const GSvector2* _position, const GSrect* _rect, const GScolor* _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f), const GSvector2& offset = GSvector2(4.0f, 4.0f))const;

	void textrue(TEXTURE_ID id, const GSvector2* _position, const GScolor* _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;
	void textrue(TEXTURE_ID id, const GSvector2* _position, const GSrect* _rect, const GScolor* _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;
	void textrue(TEXTURE_ID id, const GSvector2* _position, const GSvector2* _scaling, const GScolor* _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;

	void textrue(
		TEXTURE_ID id,
		const GSvector2* _position,
		const GSrect*    _rect,
		const GSvector2* _center,
		const GSvector2* _scaling,
		GSfloat          _rotation,
		const GScolor*    _color = &GScolor(1.0f, 1.0f, 1.0f, 1.0f)
		)const;

	/*�����l*/
	void number(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//�؂���T�C�Y
		int point,
		const GScolor* _color = &GScolor(1, 1, 1, 1))const;

	/*�����_���\���o����*/
	void number(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//�؂���T�C�Y
		float point,
		unsigned int decimalNumber = 1,//�����_�̐�
		unsigned int digitNumber = 3,//�\�����錅��(�����_���܂�)
		const GScolor* _color = &GScolor(1, 1, 1, 1)
		)const;

	void numberShadow(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//�؂���T�C�Y
		float point,
		unsigned int decimalNumber = 1,//�����_�̐�
		unsigned int digitNumber = 3,//�\�����錅��(�����_���܂�)
		const GSvector2& offset = GSvector2(4, 4),
		const GScolor* _color = &GScolor(1, 1, 1, 1)
		)const;

	/*
	GS_FONT_NORMAL �������Ȃ�
	GS_FONT_BOLD   ����
	GS_FONT_ITALIC �C�^���b�N
	GS_FONT_UNDERLINE ����
	GS_FONT_STRIKEOUT �ŏ�����
	|(�r�b�gOR���Z�q)�ŕ����d�˂���@
	*/
	void string(const std::string& text, const GSvector2* _position, const GSuint size,
		const GScolor* _color = &GScolor(1, 1, 1, 1), const GSbitfield& fontcode = GS_FONT_NORMAL,
		const char* fontname = "MS �S�V�b�N")const;

	void initBlend()const;
	void additionBlend()const;
private:
	//������string�ɕϊ�
	const std::string numToStr(float point, unsigned int decimalNumber, unsigned int digitNumber)const;

};
#endif // !_DRAW2D_H_
