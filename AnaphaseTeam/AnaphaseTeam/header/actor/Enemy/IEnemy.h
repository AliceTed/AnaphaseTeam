/**
@file	IEnemy.h
@brief	�A�N�^�[���p�������G�̉��z�N���X
@author Hiaaki
@date	2016/12/15 Ver1.00
@date	2016/12/16 ����̕�ԂƕǂƂ̔����ǉ�
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
	@breif �R���X�g���N�^
	@param[_transform] �g�����X�t�H�[��
	@param[_modelID] ���f����ID
	@param[_mediator] �G�l�~�[�̒����
	*/
	IEnemy(const Transform& _transform, MODEL_ID _modelID, EnemyMediator& _mediator);
	/**
	@breif ���z�f�X�g���N�^
	*/
	virtual ~IEnemy() {}
	/**
	* @brief �J�����̃��b�N�I���̂��߂Ɏ��g�̃|�W�V������n��
	* @param [&_camera] �J�����R���g���[��
	* @param [&_player] plyer�|�C���^�[
	*/
	void look_at(CameraController* _camera, Player* _player);
	/**
	* @brief SP�Z��H������Ƃ��̔���
	* @detail ���g��HP���S�Č��炵�Ċm�E
	*/
	void specialDamage();
	
	/**
	* @brief ���b�N�I������HPUI�̏������o�^
	* @author Matuo
	*/
	void start_lockOn();
	/**
	* @brief ���b�N�I��HPUI�̉��
	* @author Matuo
	*/
	void end_lockOn();

	/**
	* @brief �v���C���[�Ǝ��g�Ƃ̋���
	* @return �v���C���[�Ƃ̋���[float]
	*/
	float distaceToPlayer();
	/**
	* @breif �I�������I
	* @brief �v���C���[�Ƒ��̃G�l�~�[�Ƃ̋���
	* @return ���̃G�l�~�[�Ƃ̋���[float]
	*/
	float distaceToOtherEnemy();
	/**
	* @brief �v���C���[�̕���������
	*/
	void directionToPlayer();
	/**
	* @brief targetDir���X�V
	*/
	void lookAtToPlayer();

	void scoreDamage();
	void scoreDead();
	/**
	* @brief ���݂�AI��Ԃ�
	*/
	EAI currentAIRange();
	/**
	*@breif �v���C���[�ɐڋ߂��ėǂ����m�F
	*/
	bool requestDistance(EAI _distance);
	/**
	* @brief �_���[�W��H���Ȃ����
	*/
	const bool isNotDamageState()const;
	/**
	* @brief ���S����
	*/
	const bool isDeadState() const;

	/**
	* @brief �l���鎞���ۂ�
	*/
	const bool isThink()const;
	/**
	*@breif �ǂɓ������Ă��邩
	*/
	const bool isBlocked()const { return m_isBlock; }

public://���z�֐�public
	/**
	* @brief ��������уv���C���[�Ƃ̋����ɂ���čs�������߂�
	* @param (&_player)�@�v���C���[
	*/
	virtual void think(Player* _palyer) = 0;
	/**
	*@breif �_���[�W���A������Ԃ����ނ�����
	*@param[_blowPower] �H������U���̐�����ї�
	*/
	virtual void blowDamageDecision(const GSvector3& _blowPower)=0;

protected://���z�֐�protected
		/**
		* @brief state�����������
		*/
	virtual void createStates() = 0;
	/**
	*@breif �����ɉ�����AI������
	*@param[_distace] �v���C���[�Ƃ̋���
	*@return[EAI] AI
	*/
	const EAI dicisionOfAI(float _distance)const;
	/**
	*@breif ���񂾂Ƃ��ɐ�����Ԃ�
	*@return ������ԂƂ���true
	*/
	const bool blowDead()const;
	/**
	* @brief �U�����̂����蔻�萶��
	*/
	void createAttackCollision();
	/**
	*@breif ���[�v��K�p�����Đ���
	*/
	void rotateLerp(GSquaternion* _out, float _time);
protected:
	//!�ߋ���
	static const float IEnemy::PLAYER_DISTANCE_NEAR;
	//!������
	static const float IEnemy::PLAYER_DISTANCE_MID;
	//!������
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
