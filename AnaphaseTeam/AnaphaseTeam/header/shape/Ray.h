#pragma once
#include <gslib.h>

class Map;
class Ray
{
public:
	Ray(const GSvector3& _position,const GSvector3& _direction=GSvector3(0.0f,-1.0f,0.0f));
	~Ray();

	const bool isCollitionMap(const Map& _map,GSvector3* _intersect)const;
private:
	GSvector3 m_Position;
	GSvector3 m_Direction;
};