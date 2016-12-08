#pragma once
#include "../Actor.h"
#include "../../../header/camera/CameraController.h"
#include "../../convenient/Timer.h"
//#include "../../attack/AttackIncidence.h"
#include "../../attack/AttackStatus.h"
#include "../../actor/Player/Status.h"
#include "../../attack/KnockBack.h"
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
	/**
	* @fn �_���[�W��H���Ȃ��^�C�~���O
	* @brief
	*/
	const bool isNotDamageState()const;
private:
	/**
	* @fn
	* @brief �������͂���
	* @param
	*/
	const bool isNear(float _distance)const;
	/**
	* @fn
	* @brief �l���鎞���ۂ�
	*/
	const bool isThink()const;
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
	static const float PLAYER_DISTANCE;
	float m_alpha;
	Status m_status;

	KnockBack m_knockBack;
private://state
	class EAttackState;
	class EDamageState;
	class EMoveState;
	class EStandState;
	class ESlideState;
	class ESpawnState;
	class EDeadState;

	friend EAttackState;
	friend EDamageState;
	friend EMoveState;
	friend EStandState;
	friend ESlideState;
	friend ESpawnState;
	friend EDeadState;
private://collision
	class EnemyCollision;
	class EnemyAttackCollision;

	friend EnemyCollision;
	friend EnemyAttackCollision;
};
