#pragma once
#ifndef _COLLISIONTABLE_H_
#define _COLLISIONTABLE_H_
/**
*@file CollisionTable.h
*@drief 判定表
*@author 松尾裕也
*@date 2016/08/19
*/
#include "../actor/Actor_Tag.h"
#include "../array/Array2D.h"
class CollisionTable
{
public:
	CollisionTable();
	~CollisionTable();
	//衝突しないタグを設定
	void setNonCollision(Actor_Tag _tag1,Actor_Tag _tag2);
	//判定を行うならtrue
	const bool isConfirmTag(Actor_Tag _tag1, Actor_Tag _tag2)const;
private:
	Array::Array2D<bool> table;
};


#endif