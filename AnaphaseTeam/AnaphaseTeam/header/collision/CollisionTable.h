#pragma once
#ifndef _COLLISIONTABLE_H_
#define _COLLISIONTABLE_H_
#include "GAMEOBJECT_TYPE.h"
#include "Array2D.h"
class CollisionTable
{
public:
	CollisionTable();
	~CollisionTable();
	
	void setNonCollision(GAMEOBJECT_TYPE type1,GAMEOBJECT_TYPE type2);
	//îªíËÇçsÇ§Ç»ÇÁtrue
	const bool isConfirmCollisionTable(GAMEOBJECT_TYPE type1, GAMEOBJECT_TYPE type2)const;
private:
	Array2D<bool> table;
};


#endif