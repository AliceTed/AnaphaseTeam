#pragma once
#ifndef _COLLISIONTABLE_H_
#define _COLLISIONTABLE_H_
/**
*@file CollisionTable.h
*@drief ����\
*@author �����T��
*@date 2016/08/19
*/
#include "../actor/Actor_Tag.h"
#include "../array/Array2D.h"
class CollisionTable
{
public:
	CollisionTable();
	~CollisionTable();
	//�Փ˂��Ȃ��^�O��ݒ�
	void setNonCollision(Actor_Tag _tag1,Actor_Tag _tag2);
	//������s���Ȃ�true
	const bool isConfirmTag(Actor_Tag _tag1, Actor_Tag _tag2)const;
private:
	Array::Array2D<bool> table;
};


#endif