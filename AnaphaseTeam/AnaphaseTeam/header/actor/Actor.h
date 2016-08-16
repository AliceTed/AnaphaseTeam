/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
#include "../Transform.h"
#include "../shape/Sphere.h"
class Renderer;
class Camera;
class Actor
{
public:
	Actor(const Transform &_transform,const Sphere& _sphere);
	virtual ~Actor() {}
	virtual void initialize();
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer& _renderer,const Camera& _camera) = 0;
	virtual void finish();
public:
	const bool isDead()const;
	
protected:
	void alphaBlend(const Camera& _camera);
	const bool isInsideView(const Camera& _camera)const;
protected:
	Transform m_transform;
	bool m_isDead;

	GScolor color;
	/*private:*/protected://デバック描画用
	//!カメラ用判定
	Sphere m_Sphere;
	static const float ALPHABLEND_FAR;
};
