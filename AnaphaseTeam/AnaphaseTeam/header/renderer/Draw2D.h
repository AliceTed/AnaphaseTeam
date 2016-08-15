#pragma once
#ifndef _DRAW2D_H_
#define _DRAW2D_H_
#include <gslib.h>
#include <string>
#include "../data/TEXTURE_ID.h"

//数字文字列
typedef std::string NumString;
class Draw2D
{
public:
	//数字を格納した文字列

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

	void number(
		TEXTURE_ID id,
		const NumString& _number,
		const GSvector2& _position,
		const GSvector2& cuttingSize=GSvector2(64.0f,32.0f),
		const GScolor* _color = &GScolor(1, 1, 1, 1))const;

	/*整数値*/
	void number(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//切り取りサイズ
		int point,
		const GScolor* _color = &GScolor(1, 1, 1, 1))const;

	/*小数点も表示出来る*/
	void number(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//切り取りサイズ
		float point,
		unsigned int decimalNumber = 1,//小数点の数
		unsigned int digitNumber = 3,//表示する桁数
		const GScolor* _color = &GScolor(1, 1, 1, 1)
		)const;

	void numberShadow(
		TEXTURE_ID id,
		const GSvector2& _position,
		const GSvector2& cuttingSize,//切り取りサイズ
		float point,
		unsigned int decimalNumber = 1,//小数点の数
		unsigned int digitNumber = 3,//表示する桁数
		const GSvector2& offset = GSvector2(4, 4),
		const GScolor* _color = &GScolor(1, 1, 1, 1)
		)const;

	/*
	GS_FONT_NORMAL 何もしない
	GS_FONT_BOLD   太字
	GS_FONT_ITALIC イタリック
	GS_FONT_UNDERLINE 下線
	GS_FONT_STRIKEOUT 打消し線
	|(ビットOR演算子)で複数重ねられる　
	*/
	void string(const std::string& text, const GSvector2* _position, const GSuint size,
		const GScolor* _color = &GScolor(1, 1, 1, 1), const GSbitfield& fontcode = GS_FONT_NORMAL,
		const char* fontname = "メイリオ")const;

	void initBlend()const;
	void additionBlend()const;

	/**
	* @fn
	* @brief 数字文字列に変換
	* @param (_number) 変換する数値
	* @param ( _decimal) 小数点の数
	* @param ( _digit) 表示する全体の桁数
	* @return 変換後の数字文字列
	*/
	const NumString transformToNumString(float _number,GSuint _decimal, GSuint _digit)const;
};
#endif // !_DRAW2D_H_
