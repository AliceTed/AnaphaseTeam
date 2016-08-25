#pragma once
#ifndef _COLLISIONTABLE_H_
#define _COLLISIONTABLE_H_
#include "../actor/Actor_Tag.h"
#include "../array/Array2D.h"
class CollisionTable
{
public:
	CollisionTable();
	~CollisionTable();
	
	void setNonCollision(Actor_Tag _tag1,Actor_Tag _tag2);
	//îªíËÇçsÇ§Ç»ÇÁtrue
	const bool isConfirmTag(Actor_Tag _tag1, Actor_Tag _tag2)const;
private:
	Array::Array2D<bool> table;
};


#endif