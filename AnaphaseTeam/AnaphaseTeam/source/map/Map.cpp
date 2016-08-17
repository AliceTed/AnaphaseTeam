#include "..\..\header\map\Map.h"
#include "../../header/data/CastID.h"
#include "../../header/renderer/Renderer.h"
Map::Map(OCTREE_ID _id)
	:m_ID(_id)
{
}

Map::~Map()
{
}

const bool Map::isCollisionRay(const GSvector3 & _position, const GSvector3 & _direction, GSvector3 * _intersect)const
{
	Data::CastID cast;
	return gsOctreeCollisionRay(gsGetOctree(cast(m_ID)),&_position,&_direction,_intersect, NULL)==GS_TRUE;
}

const bool Map::isCollisionSphere(const GSvector3 & _center, float _radius, GSvector3* _out_center) const
{
	Data::CastID cast;
	return gsOctreeCollisionSphere(gsGetOctree(cast(m_ID)),&_center,_radius,_out_center) == GS_TRUE;
}

void Map::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawOctree(m_ID);
}
