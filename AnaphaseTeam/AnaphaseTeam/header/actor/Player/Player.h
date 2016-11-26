#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include<gslib.h>
#include "../Actor.h"
#include "../../animation/Animation.h"
#include "../../animation/AnimMediator.h"
#include "../../attack/attackManager.h"
#include "../../data/ANIMATION_ID.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "specialSkill/SpecialSkillManager.h"
class GameDevice;
class CameraController;
class TestActor;
class LockOn;
class Enemy;
class Camera;
class Player :public Actor
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
	void gaugeAdd();
	void createAttackCollision();
	void hpDown();
	void recovery();
public:
	const bool isEndAttack() const;
public://����
	//�ߐڗp
	const bool isSlowAttack()const;
	const bool isQuickAttack()const;
public://Actor�p��
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

	Camera * m_camera;
	LockOn* m_lockon;
	Scythe m_scythe;
	SpecialSkillManager m_SpecialSkillManager;

	GSvector3 target;
private://state�錾
	class AttackState;
	class DamageState;
	class MoveState;
	class StandState;
	class StepState;
	/*
	�󒆏�Ԃŕʂō��̂ł͂Ȃ�
	�v���C���[�̏�ԂƂ��Ċe��ǉ�����
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
private://Collision�錾
	class PlayerCollision;
	friend PlayerCollision;
	class SpecialAttackCollision;
	friend SpecialAttackCollision;
private://�萔
	static const float ROTATESPEED;
};