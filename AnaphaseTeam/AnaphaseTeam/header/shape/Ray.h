#pragma once
#include <gslib.h>
/**
* @file Ray.h
* @brief Rayクラス
* @author 松尾裕也
* @date 2016/8/17
*/
class Map;
class Ray
{
public:
	Ray(const GSvector3& _position,const GSvector3& _direction=GSvector3(0.0f,-1.0f,0.0f));
	~Ray();

	/**
	* @fn
	* @brief Mapとの判定
	* @param (_map) マップ取得
	* @param (_intersect) 交点
	*/
	const bool isCollitionMap(const Map& _map,GSvector3* _intersect)const;
private:
	GSvector3 m_Position;
	GSvector3 m_Direction;
};