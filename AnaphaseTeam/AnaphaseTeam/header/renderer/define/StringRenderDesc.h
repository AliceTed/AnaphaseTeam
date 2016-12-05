#pragma once

#include "Type.h"
#include <string>

//フォントの指定
struct  Font
{
	//修飾コード
	static const unsigned int CODE_NOMAL     = 0; //指定なし
	static const unsigned int CODE_BOLD      = (1 << 0);  //強調
	static const unsigned int CODE_ITALIC    = (1 << 1);//イタリック
	static const unsigned int CODE_UNDERLINE = (1 << 2);//アンダーライン
	static const unsigned int CODE_STRIKEOUT = (1 << 3);//取り消し線

	Font():
		code(CODE_NOMAL),
		size(16),
		name("ＭＳ ゴシック")
	{}

	int code;//修飾コード
	int size;//フォントサイズ
	std::string name;//フォント名
};


//文字列レンダリング記述子
struct StringRenderDesc
{
	StringRenderDesc():
		font(),
		string(""),
		position(0,0),
		color(1,1,1,1)
	{}

	Font font; //フォント
	std::string string;//文字列
	Vector2 position; //表示座標
	Color4 color; //カラー
};