#include "..\..\header\map\Map.h"
#include "../../header/data/id/CastID.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/data/id/SHADER_ID.h"
#include "../../header/renderer/define/LightDesc.h"
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
	return gsOctreeCollisionRay(gsGetOctree(cast(m_ID)),&(_position),&_direction,_intersect, NULL)==GS_TRUE;
}

const bool Map::isCollisionSphere(const GSvector3 & _center, float _radius, GSvector3* _out_center) const
{
	Data::CastID cast;
	return gsOctreeCollisionSphere(gsGetOctree(cast(m_ID)), &(_center),_radius,_out_center) == GS_TRUE;
}

void Map::draw(IRenderer * _renderer)
{

	gsBeginShader(static_cast<GSuint>(SHADER_ID::OCTREE));
	gsSetShaderParamMatrix4("u_matView", &_renderer->getViewMatrix());
	gsSetShaderParamMatrix4("u_matProjection", &_renderer->getProjectionMatrix());
	//gsSetShaderParam1f("u_fogStart", 0.5f);
	//gsSetShaderParam1f("u_fogEnd", 1);
	//gsSetShaderParam4f("u_fogColor", &GScolor(1, 0, 0, 1));

	gsTextureBind(gsGetOctree(static_cast<GSuint>(m_ID))->pMesh->pMaterials->pTexture);
	gsSetShaderParamTexture("u_baseMap", 0);
	
	gsDrawOctreeEx(static_cast<unsigned int>(OCTREE_ID::PHASE1), &_renderer->getProjectionMatrix(), &_renderer->getViewMatrix());
	gsEndShader();
}
