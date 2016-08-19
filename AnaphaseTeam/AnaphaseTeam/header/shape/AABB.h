#pragma once
#ifndef _BOXAABB_H_
#define _BOXAABB_H_
#include <gslib.h>
#include "Shape.h"
class Renderer3D;
/*
AABB(回転不可)
*/
struct AABB:public Shape
{
	AABB(const GSvector3& position,const GSvector3& radius);
	~AABB();

	//重なっているか
	const bool intersects(const AABB& other)const;
	//平行移動(加算)
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	//サイズ拡張
	void expand(const GSvector3& _size);

	const float point_distance(const GSvector3& point)const;
	const float margin(float max, float min, float point) const;

	void draw(const Renderer3D& renderer);
	const SHAPETYPE getType()const;

	GSvector3 position;//左上
	GSvector3 radius;//幅、高さ
};

#endif