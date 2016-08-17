/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
#include "../Transform.h"
#include "../shape/Sphere.h"

class Map;
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

	virtual void collisionGround(const Map& _map);

	void cameraChases(Camera& _camera);
	const float cameraDistance(const Camera& _camera)const;

public:
	const bool isDead()const;
	
protected:
	/**
	* @fn
	* @brief カメラとの距離からα値を調整
	* @param (_camera) カメラを取得
	*/
	void alphaBlend(const Camera& _camera);
	/**
	* @fn
	* @brief カメラに映っているか判定
	* @param (_camera) カメラを取得
	* @return カメラに映っているか？
	*/
	const bool isInsideView(const Camera& _camera)const;
	/**
	* @fn
	* @brief カメラ用球をActorに追従させる
	* @param (_offset)調整
	* @sa 参照すべき関数を書けばリンクが貼れる
	* @detail 詳細な説明
	*/
	void sphereChases(const GSvector3 &_offset=GSvector3(0,0,0));

	/**
	* @fn
	* @brief カメラ用球を描画(debug用)
	* @param (_renderer)描画機能クラス
	*/
	void sphereDraw(const Renderer& _renderer);
protected:
	Transform m_transform;
	bool m_isDead;

	GScolor m_Color;
private:
	//!カメラ用判定
	Sphere m_Sphere;
	//!αブレンドを始める距離
	static const float ALPHABLEND_FAR;
};
