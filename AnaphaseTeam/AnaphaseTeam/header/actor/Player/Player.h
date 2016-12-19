#pragma once
/**
*@file Player.h
*@drief プレイヤークラス
*@author 久秋雅
*@date 2016/08/12
*/
#include<gslib.h>
#include "../Actor.h"
#include "../../attack/ComboAttack.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "../../specialskill/SpecialSkillManager.h"
#include "../../ui/SpecialSkillUI.h"
#include "../../attack/Revision.h"
#include "../../convenient/Timer.h"

class CameraController;
class LockOn;
class Goblin;
class Camera;

class EnemyManager;

class Player :public Actor
{
public:
	Player(const Transform& _t,Camera * _camera, LockOn* _lockon);
	~Player();
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);
	void attackmotion(Attack& _attack);
	void look_at(CameraController* _camera, GSvector3* _target);
	void look_at(CameraController* _camera);
	void revision();
	void createAttackCollision(const ShapeData& _data);
	void damage(const AttackStatus & _attackStatus) override;
	void finish() override;
	
	void targetFind(EnemyManager * _enemys);
	void recovery();

	//マスター前の仮実装
	//要リファクタ
	const float getAttackSpeed() const;
public://Actor継承
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
	const float stepDistance() const ;
	void lookTarget();
	const bool aerialTracking() const;
	void specialSkill();
private:
	ComboAttack m_combo;
	Status m_status;
	std::shared_ptr<Gauge> m_Gauge;
	std::shared_ptr<SpecialSkillUI> m_specialUI;
	Camera * m_camera;
	LockOn* m_lockon;
	Scythe m_scythe;
	SpecialSkillManager m_specialskill;
	GSvector3 m_target;
	Revision m_Revision;
	Timer m_timer;
	bool m_isLockOn;
	
private://state宣言
	class AttackState;
	class DamageState;
	class MoveState;
	class StandState;
	class StepState;
	class SpecialAttackState;
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
	friend SpecialAttackState;
	
	friend StepState;
	friend SingleJumpState;
	friend DoubleJumpState;
	friend LimitFallState;
	friend LandingRigidityState;
private://Collision宣言
	class PlayerCollision;
	friend PlayerCollision;
	class PlayerAttackCollision;
	friend PlayerAttackCollision;
	class SpecialAttackCollision;
	friend SpecialAttackCollision;
private://定数
	static const float ROTATESPEED;
};