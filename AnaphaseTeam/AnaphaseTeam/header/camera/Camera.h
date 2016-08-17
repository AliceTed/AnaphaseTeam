#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <gslib.h>
class Camera
{
public:
	Camera(float range_Position,float range_Eye,const GSvector3& offset);
	~Camera();
	void lookAt(const GSvector3& target, float dir);

	const bool isFrustumCulling(const GSvector3& center,float radius )const;

	const float nearDistance(const GSvector3& ohter,float radius)const;

	const float distance(const GSvector3& ohter)const;
private:
	float m_near;
	float m_far;
		 
	float range_Position;	
	float range_Eye;
	GSvector3 offset;
	GSvector3 position;
};
#endif