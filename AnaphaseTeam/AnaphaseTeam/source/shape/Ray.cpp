#include "../../header/shape/Ray.h"
#include "../../header/map/Map.h"
Ray::Ray(const GSvector3 & _position, const GSvector3 & _direction)
	:m_Position(_position),m_Direction(_direction)
{
}

Ray::~Ray()
{
}

const bool Ray::isCollitionMap(const Map & _map,GSvector3* _intersect)const
{
	return _map.isCollisionRay(m_Position,m_Direction,_intersect);
}
