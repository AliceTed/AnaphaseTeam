/**
@file	IEnemy.h
@brief	アクターを継承した敵の仮想クラス
@author Hiaaki
@date	2016/12/15 Ver1.00
@date	2016/12/16 旋回の補間と壁との判定を追加
*/

#pragma once
#include "../Actor.h"
#include "camera/CameraController.h"
#include "convenient/Timer.h"
#include "attack/AttackStatus.h"
#include "actor/Player/Status.h"
#include "attack/KnockBack.h"
#include "state/enemy/EnemyAIController.h"
#include "actor\Enemy\EnemyRotateTimer.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;

class IEnemy :public Actor
{
public:
	/**
	@breif コンストラクタ
	@param[_transform] トランスフォーム
	@param[_modelID] モデルのID
	@param[_mediator] エネミーの仲介者
	*/
	IEnemy(const Transform& _transform, MODEL_ID _modelID, EnemyMediator& _mediator);
	/**
	@breif 仮想デストラクタ
	*/
	virtual ~IEnemy() {}
	/**
	* @brief カメラのロックオンのために自身のポジションを渡す
	* @param [&_camera] カメラコントロール
	* @param [&_player] plyerポインター
	*/
	void look_at(CameraController* _camera, Player* _player);
	/**
	* @brief SP技を食らったときの反応
	* @detail 自身のHP分全て減らして確殺
	*/
	void specialDamage();
	
	/**
	* @brief ロックオン時のHPUIの初期化登録
	* @author Matuo
	*/
	void start_lockOn();
	/**
	* @brief ロックオンHPUIの解放
	* @author Matuo
	*/
	void end_lockOn();

	/**
	* @brief プレイヤーと自身との距離
	* @return プレイヤーとの距離[float]
	*/
	float distaceToPlayer();
	/**
	* @breif ！未実装！
	* @brief プレイヤーと他のエネミーとの距離
	* @return 他のエネミーとの距離[float]
	*/
	float distaceToOtherEnemy();
	/**
	* @brief プレイヤーの方向を向く
	*/
	void directionToPlayer();
	/**
	* @brief targetDirを更新
	*/
	void lookAtToPlayer();

	void scoreDamage();
	void scoreDead();
	/**
	* @brief 現在のAIを返す
	*/
	EAI currentAIRange();
	/**
	*@breif プレイヤーに接近して良いか確認
	*/
	bool requestDistance(EAI _distance);
	/**
	* @brief ダメージを食らわない状態
	*/
	const bool isNotDamageState()const;
	/**
	* @brief 死亡判定
	*/
	const bool isDeadState() const;

	/**
	* @brief 考える時か否か
	*/
	const bool isThink()const;
	/**
	*@breif 壁に当たっているか
	*/
	const bool isBlocked()const { return m_isBlock; }

public://仮想関数public
	/**
	* @brief 乱数およびプレイヤーとの距離によって行動を決める
	* @param (&_player)　プレイヤー
	*/
	virtual void think(Player* _palyer) = 0;
	/**
	*@breif ダメージ時、吹っ飛ぶか怯むだけか
	*@param[_blowPower] 食らった攻撃の吹っ飛び力
	*/
	virtual void blowDamageDecision(const GSvector3& _blowPower)=0;

protected://仮想関数protected
		/**
		* @brief stateを初期化代入
		*/
	virtual void createStates() = 0;
	/**
	*@breif 距離に応じてAIを決定
	*@param[_distace] プレイヤーとの距離
	*@return[EAI] AI
	*/
	const EAI dicisionOfAI(float _distance)const;
	/**
	*@breif 死んだときに吹っ飛ぶか
	*@return 吹っ飛ぶときはtrue
	*/
	const bool blowDead()const;
	/**
	* @brief 攻撃時のあたり判定生成
	*/
	void createAttackCollision();
	/**
	*@breif ラープを適用させて旋回
	*/
	void rotateLerp(GSquaternion* _out, float _time);
protected:
	//!近距離
	static const float IEnemy::PLAYER_DISTANCE_NEAR;
	//!中距離
	static const float IEnemy::PLAYER_DISTANCE_MID;
	//!遠距離
	static const float IEnemy::PLAYER_DISTANCE_FAR;

	float m_alpha;
	Status m_status;
	EnemyMediator& m_mediator;
	EnemyAIController m_AI;
	KnockBack m_knockBack;

	GSquaternion m_targetDirection;
	LerpTimer m_rotateTimer;
	float m_gravity;

protected:
	class EnemyCollision;
	class EnemyAttackCollision;

	friend EnemyCollision;
	friend EnemyAttackCollision;

};
