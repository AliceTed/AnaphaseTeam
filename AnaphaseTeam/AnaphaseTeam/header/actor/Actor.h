/**
*@file Actor.h
*@drief キャラの親クラス
*@author 渋谷知樹
*@date 2016/08/11
*/
#pragma once
#include <unordered_map>
#include <memory>
#include "../../header/transform/Transform.h"
#include "../data/id/Model_ID.h"
#include "../animation/AnimatorOne.h"
#include "../actor/Actor_Tag.h"
#include "../collision/CollisionGroup.h"
#include "../state/ACTOR_STATE.h"

#include "../../header/attack/KnockBack.h"

struct AttackStatus;
class IRenderer;
class Map;
class IActorState;
class Actor
{
public:
	Actor(const Transform &_transform,const MODEL_ID _model_ID, Actor_Tag _tag,float _offset=0.0f);
	virtual ~Actor();
	virtual void initialize();
	virtual void update(float deltatime) = 0;
	virtual void draw(IRenderer* _renderer) = 0;
	virtual void finish();	
	virtual void damage(const AttackStatus& _attackStatus) = 0;

public:
	/**
	* @fn
	* @brief Mapとの衝突関数
	* @param (_map) mapを取得
	*/
	void collisionGround(const Map& _map);
	//現在の状態を返す
	const ACTOR_STATE getState() const;
	void collision(Actor& _other);
	const bool isDead()const;
	const bool isSameActor(const Actor* _other)const;
	const bool isSameTag(Actor_Tag _tag)const;
	void changeState(ACTOR_STATE _state);

	void changeGravity(float _gravity);

protected:	
	void action(float deltaTime);
	void registerState(ACTOR_STATE _name, IActorState* _state);
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
	//_targetの方向を求める
	const GSquaternion targetDirection(const Actor& _target)const;

	const bool isTargetAerial(const Actor& _target)const;
private:
	//コピー禁止
	Actor(const Actor&);
	Actor& operator=(const Actor&);

protected:
	Transform m_transform;
	bool m_isDead;
	bool m_isGround;
	//行動可能
	bool m_isBlock;
	AnimatorOne m_animatorOne;
	CollisionGroup m_collision;
	float m_gravity;
private:
	using StatePtr = std::shared_ptr<IActorState>;
	using StateContainer = std::unordered_map< ACTOR_STATE, StatePtr>;
	StateContainer m_states;
	StatePtr m_currentState;
	ACTOR_STATE m_currentStateKey;

	GSvector3 m_previousIntersect;
	Actor_Tag m_Tag;

	//地面との
	float m_offset;
	//重力
	static const float GRAVITY;
};
