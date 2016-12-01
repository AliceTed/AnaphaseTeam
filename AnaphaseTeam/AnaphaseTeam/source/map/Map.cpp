#include "..\..\header\map\Map.h"
#include "../../header/data/id/CastID.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/OctreeRenderDesc.h"
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

void Map::draw(IRenderer * _renderer)
{
	OctreeRenderDesc desc;
	desc.octreeID = static_cast<GSuint>(m_ID);
	_renderer->render(desc);
}
