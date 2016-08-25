#pragma once
#ifndef _COLLISIONTABLE_H_
#define _COLLISIONTABLE_H_
/**
*@file CollisionTable.h
*@drief »è\
*@author ¼öTç
*@date 2016/08/19
*/
#include "../actor/Actor_Tag.h"
#include "../array/Array2D.h"
class CollisionTable
{
public:
	CollisionTable();
	~CollisionTable();
	//ÕËµÈ¢^OðÝè
	void setNonCollision(Actor_Tag _tag1,Actor_Tag _tag2);
	//»èðs¤Èçtrue
	const bool isConfirmTag(Actor_Tag _tag1, Actor_Tag _tag2)const;
private:
	Array::Array2D<bool> table;
};


#endif