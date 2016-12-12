#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
//#include "../../attack/AttackIncidence.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
#include "../../attack/KnockBack.h"
#include "../../state/enemy/EnemyAIController.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;

class Enemy :public Actor
{
public:
	Enemy(const Transform& _transform,EnemyMediator& _mediator);
	~Enemy();
	void initialize() override;
	void update(float deltatime)override;
	void draw(IRenderer* _renderer)override;
	/**
	* @fn
	* @brief �_���[�W�X�e�[�g�ɐ؂�ւ�HP���}�C�i�X
	* @param (&_attackStatus) Player�̃X�e�[�^�X
	*/
	void damage(const AttackStatus& _attackStatus)override;
public:
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
	* @brief ��������уv���C���[�Ƃ̋����ɂ���čs�������߂�
	* @param (&_player)�@�v���C���[
	*/
	void think(Player* _palyer);
	/**
	* @fn
	* @brief ���b�N�I������HPUI�̏������o�^
	*/
	void start_lockOn();
	float distaceToPlayer();
	float distaceToOtherEnemy();
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
	*/
	const bool isDamageState()const;
	const bool isDeadState() const;

	/**
	* @fn
	* @brief �l���鎞���ۂ�
	*/
	const bool isThink()const;
private:
	const EAI isNear(float _distance)const;
	const bool blowDead()const;
	
private:
	/**
	* @fn
	* @brief �������͂���
	* @param
	*/
	//	const bool isNear(float _distance)const;

		/**
		* @fn
		* @brief state�����������
		*/
	void createStates();
	/**
	* @fn
	* @brief �U�����̂����蔻�萶��
	*/
	void createAttackCollision();
private:
	static const float Enemy::PLAYER_DISTANCE_NEAR;
	static const float Enemy::PLAYER_DISTANCE_MID;
	static const float Enemy::PLAYER_DISTANCE_FAR;
	float m_alpha;
	Status m_status;
	EnemyMediator& m_mediator;
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
