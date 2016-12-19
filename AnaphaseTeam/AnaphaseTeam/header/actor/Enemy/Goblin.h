#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
#include "../../attack/KnockBack.h"
#include "../../state/enemy/EnemyAIController.h"
#include "IEnemy.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;

class Goblin :public IEnemy
{
public://Actor継承、コンストラクタ
	Goblin(const Transform& _transform, EnemyMediator& _mediator);
	~Goblin();
	void initialize() override;//actor
	void update(float deltatime)override;//actor
	void draw(IRenderer* _renderer)override;//actor
	/**
	* @fn
	* @brief ダメージステートに切り替えHPをマイナス
	* @param (&_attackStatus) Playerのステータス
	*/
	void damage(const AttackStatus& _attackStatus)override;//actor


private:
	/**
	* @fn
	* @brief stateを初期化代入
	*/
	void createStates()override;
	void think(Player* _palyer)override;
private:

	GSquaternion m_debug;
private://state
	class EAttackState;
	class EDamageState;
	class EMoveState;
	class EStandState;
	class ESlideState;
	class ESpawnState;
	class EDeadState;
	class EMoveBackState;
	class EDashFrontState;
	class EThinkState;
	class ESecoundAttackState;

	friend EAttackState;
	friend EDamageState;
	friend EMoveState;
	friend EStandState;
	friend ESlideState;
	friend ESpawnState;
	friend EDeadState;
	friend EMoveBackState;
	friend EDashFrontState;
	friend EThinkState;
	friend ESecoundAttackState;
};
