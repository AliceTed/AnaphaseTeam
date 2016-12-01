#pragma once
/**
*@file Player.h
*@drief �v���C���[�N���X
*@author �v�H��
*@date 2016/08/12
*/
#include<gslib.h>
#include "../Actor.h"
#include "../../attack/ComboAttack.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "../../specialskill/SpecialSkillManager.h"

class CameraController;
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
	void homing();
	void createAttackCollision();
public://Actor�p��
	void initialize() override;
	void update(float deltatime) override;
	void draw(IRenderer* _renderer) override;
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
	SpecialSkillManager m_specialskill;

	GSvector3 target;
private://state�錾
	class AttackState;
	class DamageState;
	class MoveState;
	class StandState;
	class StepState;
	class SpecialAttackState;
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
	friend SpecialAttackState;
	
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