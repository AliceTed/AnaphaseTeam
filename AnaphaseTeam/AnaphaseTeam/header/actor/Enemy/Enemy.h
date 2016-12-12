#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
//#include "../../attack/AttackIncidence.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
#include "../../attack/KnockBack.h"
#include "../../state/enemy/EnemyAIController.h"
class IEnemyAI;
class EnemyCollision;
class Player;

class Enemy :public Actor
{
public:
	Enemy(const Transform& _transform);
	~Enemy();
	void initialize() override;
	void update(float deltatime)override;
	void draw(IRenderer* _renderer)override;
	/**
	* @fn
	* @brief ダメージステートに切り替えHPをマイナス
	* @param (&_attackStatus) Playerのステータス
	*/
	void damage(const AttackStatus& _attackStatus)override;
public:
	/**
	* @fn
	* @brief カメラのロックオンのために自身のポジションを渡す
	* @param (&_camera) カメラコントロール
	* @param (&_player) plyerポインター
	*/
	void look_at(CameraController* _camera, Player* _player);
	/**
	* @fn
	* @brief SP技を食らったときの反応（HP分全部減らして確殺）
	*/
	void specialDamage();
	/**
	* @fn
	* @brief 乱数およびプレイヤーとの距離によって行動を決める
	* @param (&_player)　プレイヤー
	*/
	void think(Player* _palyer);
	void distanceThink(float _distance);
	/**
	* @fn
	* @brief ロックオン時のHPUIの初期化登録
	*/
	void start_lockOn();
	/**
	* @fn ダメージを食らわないタイミング
	* @brief
	*/
	const bool isNotDamageState()const;
	/**
	* @fn
	* @brief 距離をはかる
	* @param
	*/
	const bool isDamageState()const;
	const bool isDeadState() const;

	/**
	* @fn
	* @brief 考える時か否か
	*/
	const bool isThink()const;
private:
	const bool isNear(float _distance)const;
	const bool blowDead()const;
	
private:
	/**
	* @fn
	* @brief 距離をはかる
	* @param
	*/
	//	const bool isNear(float _distance)const;

		/**
		* @fn
		* @brief stateを初期化代入
		*/
	void createStates();
	/**
	* @fn
	* @brief 攻撃時のあたり判定生成
	*/
	void createAttackCollision();
private:
	static const float PLAYER_DISTANCE;
	float m_alpha;
	Status m_status;
	EnemyAIController m_AI;
	KnockBack m_knockBack;
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
private://collision
	class EnemyCollision;
	class EnemyAttackCollision;

	friend EnemyCollision;
	friend EnemyAttackCollision;
};
