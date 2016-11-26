#pragma once
/**
*@file Player.h
*@drief プレイヤークラス
*@author 久秋雅
*@date 2016/08/12
*/
#include<gslib.h>
#include "../Actor.h"
#include "../../animation/Animation.h"
#include "../../animation/AnimMediator.h"
#include "../../../header/subAction/Avoid.h"
#include "../../attack/attackManager.h"
#include "../../data/ANIMATION_ID.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "specialSkill/SpecialSkillManager.h"
class GameDevice;
class CameraController;
class TestActor;
class Boss;
class LockOn;
class Enemy;
class PlayerCollision;
class Camera;
class Player :public Actor,public AnimMediator
{
public:
	Player(GameDevice* _device, Camera * _camera, LockOn* _lockon);
	~Player();
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);
	void attackmotion(IAttack& _attack);
	const bool isNextAttack(const IAttack& _attack)const;
	const bool isEndAttackMotion(const IAttack& _attack)const;
	void control();
	void look_at(CameraController* _camera, GSvector3* _target);
	void subActionStart();
	void gaugeUp(float _scale);
	void attackHoming(Enemy* _boss);
	void homing();
	void specialAttack();
	void changeAnimation(unsigned int _animID);
	void gaugeAdd();
	void createAttackCollision();
	void hpDown();
	void recovery();
public:
	const bool isJumpAttack()const;
	const bool isEndAttack() const;
public://入力
	const bool isAvoid() const;
	//近接用
	const bool isSlowAttack()const;
	const bool isQuickAttack()const;
	//入力方向
	const GSvector3 inputDirection()const;
public://Actor継承
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer) override;
private:
	void createStates();
	void rotate(float deltaTime, Transform& _transform);
	void movement(float deltaTime, float _speed);
private:
	GameDevice* m_device;	
	AttackManager m_attackManager;
	Status m_status;
	Gauge m_Gauge;
	//無理やり
	bool m_isJumpAttack;
	Camera * m_camera;
	LockOn* m_lockon;
	Scythe m_scythe;
	Avoid m_avoid;
	SpecialSkillManager m_SpecialSkillManager;

	GSvector3 target;
private://state宣言
	class AttackState;
	class DamageState;
	class MoveState;
	class StandState;
	class StepState;
	/*
	空中状態で別で作るのではなく
	プレイヤーの状態として各種追加する
	*/
	class SingleJumpState;
	class DoubleJumpState;
	class LimitFallState;
	class LandingRigidityState;

	friend AttackState;
	friend DamageState;
	friend MoveState;
	friend StandState;
	friend StepState;

	friend SingleJumpState;
	friend DoubleJumpState;
	friend LimitFallState;
	friend LandingRigidityState;
private://Collision宣言
	class PlayerCollision;
	friend PlayerCollision;
	class SpecialAttackCollision;
	friend SpecialAttackCollision;
private://定数
	static const float ROTATESPEED;
};