#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_
/**
* @file Sphere.h
* @brief ���`�� �N���X
* @author �����T��
* @date 2016/8/14
*/
#include "Shape.h"

class Camera;//CameraManager�ɂȂ邩��
class Map;
class Sphere:public Shape
{
public:
	Sphere(const GSvector3& center,float radius);
	~Sphere();
	void expand(float radius);
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);

public:
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;
	const bool isCollision(const AABB* _aabb)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer& renderer,const GScolor& color=GScolor(1.0f, 1.0f, 1.0f, 1.0f));
public:
	const bool isInsideCameraView(const Camera& _camera)const;
	const float cameraDistance(const Camera& _camera)const;

	const bool isCollitionMap(const Map& _map, GSvector3* _out_center)const;
private:
	GSvector3 center;
	float radius;
};



#endif