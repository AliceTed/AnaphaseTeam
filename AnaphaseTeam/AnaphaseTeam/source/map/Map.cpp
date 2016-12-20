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
	OctreeRenderDesc desc;
	desc.octreeID =static_cast<unsigned int>(m_ID);
	_renderer->render(desc);

	/*
	clipÇ™Ç†ÇÈÇÃÇ≈Ç∆ÇËÇ†Ç¶Ç∏Ç±Ç±Ç…èëÇ¢ÇΩ
	*/
	GScolor color = { 0.3f,0.0f,0.0f,0.5f };
	GSvector2 clip = { 10, 50 };
	//glClearColor(color.r, color.g, color.b, color.a);
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, clip.x);
	glFogf(GL_FOG_END, clip.y);
	glFogfv(GL_FOG_COLOR, color);

	/*gsBeginShader(static_cast<GSuint>(SHADER_ID::OCTREE));
	LightDesc light = _renderer->getLight();
	GSvector3 light_position_eye =light.position*_renderer->getViewMatrix();
	gsSetShaderParam3f("u_lightPositionEye", &light_position_eye);
	gsSetShaderParam4f("u_lightAmbient", &light.ambient);
	gsSetShaderParam4f("u_lightDiffuse", &light.diffuse);
	gsSetShaderParam4f("u_lightSpecular", &light.specular);

	GSmatrix4 mat;
	mat.identity();
	mat.translate(m_translate);
	gsSetShaderParamMatrix4("u_matWorld", &mat);
	gsSetShaderParamMatrix4("u_matView", &_renderer->getViewMatrix());
	gsSetShaderParamMatrix4("u_matProjection", &_renderer->getProjectionMatrix());
	gsSetShaderParamTexture("u_baseMap", 0);
	gsSetShaderParamTexture("u_normalMap", 1);
	
	gsDrawOctreeEx(static_cast<unsigned int>(m_ID), &_renderer->getProjectionMatrix(), &_renderer->getViewMatrix());
	gsEndShader();*/
}
