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
#include "../../attack/ComboAttack.h"
#include "../../data/ANIMATION_ID.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "specialSkill/SpecialSkillManager.h"

class CameraController;
class TestActor;
class LockOn;
class Enemy;
class Camera;
class Player :public Actor
{
public:
	Player(Camera * _camera, LockOn* _lockon);
	~Player();
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);
	void attackmotion(Attack& _attack);
	void look_at(CameraController* _camera, GSvector3* _target);
	//void gaugeUp(float _scale);
	void homing();
	void specialAttack();
	void gaugeAdd();
	void createAttackCollision();
	void hpDown();
	void recovery();
public://Actor�p��
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer) override;
	AttackStatus status();
private:
	void subActionStart();
	void control();
	void createStates();
	void rotate(float deltaTime, Transform& _transform);
	void movement(float deltaTime, float _speed);
private:
	ComboAttack m_combo;
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
	class PlayerAttackCollision;
	friend PlayerAttackCollision;
	class SpecialAttackCollision;
	friend SpecialAttackCollision;
private://�萔
	static const float ROTATESPEED;
};