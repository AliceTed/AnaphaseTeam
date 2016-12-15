#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
#include "../../attack/KnockBack.h"
#include "../../state/enemy/EnemyAIController.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;

struct LerpTimer
{
public:
	void begin()
	{
		time = 0.0f;
		maxTime = 10.0f;
	}
	void update(float deltatime)
	{
		time += time<maxTime? deltatime * 1:0;
	}
public:
	float time=0;
	float maxTime=10.0f;
};

class IEnemy:public Actor
{
public:
	IEnemy(const Transform& _transform, MODEL_ID _modelID,EnemyMediator& _mediator);
	virtual ~IEnemy(){}
	/**
	* @fn
	* @brief �J�����̃��b�N�I���̂��߂Ɏ��g�̃|�W�V������n��
	* @param (&_camera) �J�����R���g���[��
	* @param (&_player) plyer�|�C���^�[
	*/
	void look_at(CameraController* _camera, Player* _player);
	/**
	* @fn
	* @brief SP�Z��H������Ƃ��̔����iHP���S�����炵�Ċm�E�j
	*/
	void specialDamage();
	
	/**
	* @fn
	* @brief ���b�N�I������HPUI�̏������o�^
	*/
	void start_lockOn();
	void end_lockOn();

	float distaceToPlayer();
	float distaceToOtherEnemy();
	void directionToPlayer();
	void lookAtToPlayer();
	EAI currentDistance();
	bool requestDistance(EAI _distance);
	/**
	* @fn �_���[�W��H���Ȃ��^�C�~���O
	* @brief
	*/
	const bool isNotDamageState()const;
	/**
	* @fn
	* @brief �������͂���
	* @param

	const bool isDamageState()const;*/
	const bool isDeadState() const;
	/**
	* @fn
	* @brief �l���鎞���ۂ�
	*/
	const bool isThink()const;
public:
	/**
	* @fn
	* @brief ��������уv���C���[�Ƃ̋����ɂ���čs�������߂�
	* @param (&_player)�@�v���C���[
	*/
	virtual void think(Player* _palyer)=0;
	void directionLerpBegin();
protected:
		/**
		* @fn
		* @brief state�����������
		*/
	virtual void createStates()=0;
	const EAI isNear(float _distance)const;
	const bool blowDead()const;

	/**
	* @fn
	* @brief �U�����̂����蔻�萶��
	*/
	void createAttackCollision();
protected:
	static const float IEnemy::PLAYER_DISTANCE_NEAR;
	static const float IEnemy::PLAYER_DISTANCE_MID;
	static const float IEnemy::PLAYER_DISTANCE_FAR;

	float m_alpha;
	Status m_status;
	EnemyMediator& m_mediator;
	EnemyAIController m_AI;
	KnockBack m_knockBack;

	GSquaternion m_targetDirection;
	LerpTimer m_timer;
	float m_gravity;

protected:
	class EnemyCollision;
	class EnemyAttackCollision;

	friend EnemyCollision;
	friend EnemyAttackCollision;

};
