#pragma once
/**
*@file Player.h
*@drief プレイヤークラス
*@author 久秋雅
*@date 2016/08/12
*/
#include "../Actor.h"
#include "../../animation/Animation.h"
#include "../../actionstate/IActionState.h"
#include "../../convenient/Timer.h"
#include<gslib.h>
#include <memory>
#include "../Actor.h"
#include "../ICharacter.h"
#include "../../animation/AnimMediator.h"
#include "../../../header/subAction/SubActionManager.h"
#include "../../attack/attackManager.h"
#include "../../data/ANIMATION_ID.h"
#include "Status.h"
#include "../../attack/Scythe.h"
#include "Gauge.h"
#include "specialSkill/SpecialSkillManager.h"
#include "../../../header/ui/SpAttackUI.h"

#include "../../../header/collision/SpecialAttackCollision.h"
class GameDevice;
class CameraController;
class TestActor;
class Boss;
class LockOn;
class Enemy;
class PlayerCollision;

typedef std::shared_ptr<IActionState> Action_Ptr;
class Player :public Actor, public ICharacter,public AnimMediator
{
public:
	Player(GameDevice* _device,Camera * _camera, LockOn* _lockon);
	~Player();
	/**
	* @fn
	* @brief アクションステートの切り替え関数
	* @param (_action) 切り替えるアクションのShared_ptr
	*/
	void actionChange(Action_Ptr _action);
	void jumping(float _velocity);
	void avoidAction(const GSvector3& _velocity);
	void startJump(JumpControl* _control,float _scale);
	void jumpMotion(JumpControl& _control,ANIMATION_ID _id, float _animSpeed = 1.0f);
	void attackmotion(IAttack& _attack);
	const bool isNextAttack(const IAttack& _attack)const;
	const bool isEndAttackMotion(const IAttack& _attack)const;
	void moving(float deltaTime,bool isAnimation=true);
	void control();
	void look_at(CameraController* _camera, GSvector3* _target);
	void subActionStart();
	void moveStart();
	void gaugeUp(float _scale);
	void attackHoming(Enemy* _boss);
	void homing();
	void specialAttack();
	void collisionChase(SpecialAttackCollision* _collision);
	void collisionChase(PlayerCollision * _collision);
	void changeAnimation(unsigned int _animID);
	void gaugeAdd();
	void createAttackCollision();
	void hpDown();
	void recovery();
public:
	const bool isGround() const;
	const bool isJumpAttack()const;
	const bool isEndAttack() const;
	const bool isAnimationEnd() const;
public://入力
	const bool isJump() const;
	const bool isAvoid() const;
	//近接用
	const bool isSlowAttack()const;
	const bool isQuickAttack()const;
	//入力方向
	const GSvector3 inputDirection()const;
public://Actor継承
	void initialize() override;
	void update(float deltatime) override;
	void draw(const Renderer& _renderer, const Camera& _camera) override;
private:
	void inGround() override;
public://ICharacter実装
	void stand(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void move(float deltaTime);
	void jump(float deltaTime);
	void avoid(float deltaTime);
	void createColision();
private:
	void moveMotionChange();
	void rotate(float deltaTime,Transform& _transform);
	void movement(float deltaTime, float _speed = MOVESPEED);
private:
	GameDevice* m_device;
	Action_Ptr m_action;
	subActionManager m_SubAction;
	AttackManager m_attackManager;
	Status m_status;
	Gauge m_Gauge;
	//JumpControlに移動したい
	bool m_isGround;
	//無理やり
	bool m_isJumpAttack;
	Camera * m_camera;

	LockOn* m_lockon;

	Action_Ptr m_currentAction;
	Scythe m_scythe;

	Avoid m_avoid;
	SpecialSkillManager m_SpecialSkillManager;

	GSvector3 target;
private://定数
	static const float MOVESPEED;
	static const float ROTATESPEED;
	static const float WALKSPEED;
};