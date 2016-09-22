/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
#include "../convenient/Transform.h"
#include "../data/Model_ID.h"

#include "../data/ANIMATION_ID.h"
#include "../data/SKELETON_ID.h"
#include "../animation/Animator.h"
#include "../animation/AnimatorOne.h"
#include "../shape/Sphere.h"
#include "../actor/Actor_Tag.h"

class Renderer;
class CollisionMediator;
class Map;
class Camera;
class CollisionTable;

class Player;
class TestActor;
//!　引数のフラグがfalseならリターン
#define FALSE_RETURN(flg) if(!flg)return;
class Actor
{
public:
	Actor(const Transform &_transform,const MODEL_ID _model_ID,const Sphere& _sphere, Actor_Tag _tag);
	Actor(const Transform &_transform, const ANIMATION_ID _anim_ID,const SKELETON_ID _skelton_ID, const Sphere& _sphere, Actor_Tag _tag);

	virtual ~Actor() {}
	virtual void initialize();
	virtual void update(float deltatime) = 0;
	virtual void draw(const Renderer& _renderer,const Camera& _camera) = 0;
	virtual void finish();

	/**
	* @fn
	* @brief Mapとの衝突関数
	* @param (_map) mapを取得
	*/
	virtual void collisionGround(const Map& _map);
	/**
	* @fn
	* @brief 自身が作成した判定用オブジェクトが衝突したら呼ばれる
	* @param (_other)衝突したactorクラスを取得
	*/
	virtual void collision(Actor* _other);
	/**
	* @fn
	* @brief 関数内で判定用オブジェクトを生成出来る
	* @param (_mediator)判定用オブジェクトを格納できる 
	*/
	virtual void createCollision(CollisionMediator* _mediator);

	/**
	* @fn
	* @brief 地面に埋め込まれたときに呼ばれる
	*/
	virtual void inGround();
public:
	/**
	* @fn
	* @brief Actor同士の距離
	* @param (_ohter) 距離を測るActor
	* @return 距離
	*/
	const float distanceActor(const Actor& _other)const;
	//chain計算用にあるだけdistanceActor一つにしたい
	const float distance(const GSvector3& _position)const;

	const bool isSameActor(const Actor* _other)const;
	const bool isSameTag(Actor_Tag _tag)const;
	/**
	* @fn
	* @brief 判定表から衝突判定を行うactorか判断する
	* @param (_table) 判定表
	* @param (_other) 確認するactor
	*/
	const bool isConfirmCollisionTable(const CollisionTable& _table, const Actor* _other)const;
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
	//Animator m_animator;
	AnimatorOne m_animatorOne;
private:
	Actor_Tag m_Tag;

	//!カメラ用判定
	Sphere m_Sphere;
	//!αブレンドを始める距離
	static const float ALPHABLEND_FAR;
};
