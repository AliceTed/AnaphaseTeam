#pragma once

#include "Type.h"
#include <string>

//�t�H���g�̎w��
struct  Font
{
	//�C���R�[�h
	static const unsigned int CODE_NOMAL     = 0; //�w��Ȃ�
	static const unsigned int CODE_BOLD      = (1 << 0);  //����
	static const unsigned int CODE_ITALIC    = (1 << 1);//�C�^���b�N
	static const unsigned int CODE_UNDERLINE = (1 << 2);//�A���_�[���C��
	static const unsigned int CODE_STRIKEOUT = (1 << 3);//��������

	Font():
		code(CODE_NOMAL),
		size(16),
		name("�l�r �S�V�b�N")
	{}

	int code;//�C���R�[�h
	int size;//�t�H���g�T�C�Y
	std::string name;//�t�H���g��
};


//�����񃌃��_�����O�L�q�q
struct StringRenderDesc
{
	StringRenderDesc():
		font(),
		string(""),
		position(0,0),
		color(1,1,1,1)
	{}

	Font font; //�t�H���g
	std::string string;//������
	Vector2 position; //�\�����W
	Color4 color; //�J���[
};