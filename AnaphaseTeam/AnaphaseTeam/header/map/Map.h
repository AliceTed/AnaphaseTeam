#pragma once
#ifndef _MAP_H_
#define _MAP_H_
/**
* @file Map.h
* @brief octree—pƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/8/17
*/

#include "../data/id/OCTREE_ID.h"
#include <gslib.h>
class Ray;
class IRenderer;
class Map
{
public:
	Map(OCTREE_ID _id,const GSvector3&_translate=GSvector3(0,0,0));
	~Map();

	const bool isCollisionRay(const GSvector3 &_position, const GSvector3 &_direction,GSvector3* _intersect)const;
	const bool isCollisionSphere(const GSvector3 &_center,float _radius,GSvector3* _out_center)const;
	void draw(IRenderer * _renderer);
private:
	OCTREE_ID m_ID;
	GSvector3 m_translate;
};

#endif