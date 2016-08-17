#pragma once
#ifndef _RENDERER3D_H_
#define _RENDERER3D_H_

#include "../data/OCTREE_ID.h"
#include "../data/MESH_ID.h"
#include <gslib.h>
class Transform;
class Draw3D
{
public:
	Draw3D();
	~Draw3D();
	
	void drawMesh(
		MESH_ID id,
		const GSvector3* _position,
		const GSvector3*  _scaling,
		const GSvector3* axis,
		float direction)const;

	void drawMesh(MESH_ID id, const Transform& _transform, const GScolor& _color = GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;
	void drawMesh(MESH_ID id,const GSmatrix4& mat, const GScolor& _color=GScolor(1.0f,1.0f,1.0f,1.0f))const;

	void drawSky(MESH_ID id, float angle)const;
	void drawSky(MESH_ID id)const;
	void drawOctree(OCTREE_ID id)const;

	void drawBox(const GSvector3* pos,const GSvector3* radius,const GSvector3* rot, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;
	void drawSphere(const GSvector3* pos,float radius, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;
	void drawSphere(const GSmatrix4& mat, float radius, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f))const;

	void drawCapsule(const GSvector3* pos,	float radius,float hight,float dir,float ele, const GScolor& color=GScolor(1.0f,1.0f,1.0f,1.0f))const;

	void drawLine(const GSvector3* p1, const GSvector3* p2, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f),float size=1.0f)const;
};
#endif