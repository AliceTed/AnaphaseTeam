#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <gslib.h>
//#include "Shape.h"
class Renderer;
class Camera;//CameraManager‚É‚È‚é‚©‚à
/*struct*/class Sphere//:public Shape
{
public:
	Sphere(const GSvector3& center,float radius);
	~Sphere();
	void expand(float radius);
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	const bool intersects(const Sphere& other)const;
	void draw(const Renderer& renderer,const GScolor& color=GScolor(1.0f, 1.0f, 1.0f, 1.0f));
	//const SHAPETYPE getType()const;

	const bool isInsideCameraView(const Camera& _camera)const;
	const float cameraDistance(const Camera& _camera)const;
private:
	GSvector3 center;
	float radius;
};



#endif