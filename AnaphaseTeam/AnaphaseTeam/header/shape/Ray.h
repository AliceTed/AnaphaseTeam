#pragma once
#include <gslib.h>
/**
* @file Ray.h
* @brief Ray�N���X
* @author �����T��
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
	* @brief Map�Ƃ̔���
	* @param (_map) �}�b�v�擾
	* @param (_intersect) ��_
	*/
	const bool isCollitionMap(const Map& _map,GSvector3* _intersect)const;
private:
	GSvector3 m_Position;
	GSvector3 m_Direction;
};