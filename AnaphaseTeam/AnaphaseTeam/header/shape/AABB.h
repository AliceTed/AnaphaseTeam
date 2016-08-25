#pragma once
/**
*@file AABB.h
*@drief 軸並行境界ボックス(Axis-Aligned Bounding Box)
*@author 松尾裕也
*@date 2016/08/19
*/
#include "Shape.h"
class Renderer;
/*
回転が考慮されない(不可能)なBOX
*/
class AABB :public Shape
{
public:
	AABB(const GSvector3& _position, const GSvector3& _radius);
	~AABB();

	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;
	const bool isCollision(const AABB* _aabb)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer & renderer, const GScolor& color = GScolor(1, 1, 1, 1));

	const bool isCollisionSphere(const GSvector3& _center, float _radius)const;

	const bool isSlab_Ray(const GSvector3& pos, const GSvector3& dir, unsigned int index, float* t)const
	{
		*t = -FLT_MAX;
		float t_max = FLT_MAX;
		if (fabsf(dir.v[index]) < FLT_EPSILON)
		{
			return !(pos.v[index] < min().v[index] || pos.v[index] > max().v[index]); // 交差していない
		}

		// スラブとの距離を算出
		// t1が近スラブ、t2が遠スラブとの距離
		float odd = 1.0f / dir.v[index];
		float t1 = (min().v[index] - pos.v[index]) * odd;
		float t2 = (max().v[index] - pos.v[index]) * odd;
		if (t1 > t2)
		{
			float tmp = t1; t1 = t2; t2 = tmp;
		}

		if (t1 > *t) *t = t1;
		if (t2 < t_max) t_max = t2;

		// スラブ交差チェック
		return !(*t >= t_max);
	}
	/**
	* @brief　無限光線と境界ボックスとの交差判定
	* @param pos	光線の基点
	* @param dir_w 光線の方向
	* @param t	衝突間隔（出力）
	* @param colPos 衝突位置
	* @return	衝突していればtrue
	*/
	const bool isCollision_Ray(
		const GSvector3& pos,
		const GSvector3& dir,
		GSvector3* colPos = NULL)const
	{

		float t;
		for (unsigned int i = 0; i < 3; ++i)
		{
			if (!isSlab_Ray(pos, dir, i,&t))
			{
				return false;
			}
		}

		// 交差している
		if (colPos != NULL)
		{
			*colPos = pos + t * dir;
		}

		return true;
	}

	void move(GSvector3 m)
	{
		m_position += m;
	}
private:
	const float distance_point(const GSvector3& _point)const;
	const GSvector3 min()const;
	const GSvector3 max()const;
private:
	GSvector3 m_position;//中心
	GSvector3 m_radius;//幅、高さ
};