#pragma once
#ifndef _MAP_H_
#define _MAP_H_
/**
* @file Map.h
* @brief octree—pƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/8/17
*/

#include "../data/OCTREE_ID.h"
#include <gslib.h>
class Ray;
class Renderer;
class Map
{
public:
	Map(OCTREE_ID _id );
	~Map();

	const bool isCollisionRay(const GSvector3 &_position, const GSvector3 &_direction,GSvector3* _intersect)const;
	const bool isCollisionSphere(const GSvector3 &_center,float _radius,GSvector3* _out_center)const;
	void draw(const Renderer& _renderer);
private:
	OCTREE_ID m_ID;
};

#endif