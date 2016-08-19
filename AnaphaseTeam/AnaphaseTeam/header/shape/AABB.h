#pragma once
#ifndef _BOXAABB_H_
#define _BOXAABB_H_
#include <gslib.h>
#include "Shape.h"
class Renderer3D;
/*
AABB(��]�s��)
*/
struct AABB:public Shape
{
	AABB(const GSvector3& position,const GSvector3& radius);
	~AABB();

	//�d�Ȃ��Ă��邩
	const bool intersects(const AABB& other)const;
	//���s�ړ�(���Z)
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	//�T�C�Y�g��
	void expand(const GSvector3& _size);

	const float point_distance(const GSvector3& point)const;
	const float margin(float max, float min, float point) const;

	void draw(const Renderer3D& renderer);
	const SHAPETYPE getType()const;

	GSvector3 position;//����
	GSvector3 radius;//���A����
};

#endif