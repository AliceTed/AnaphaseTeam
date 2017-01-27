#pragma once
#include "../Actor.h"
#include "camera/CameraController.h"
#include "convenient/Timer.h"
#include "attack/AttackStatus.h"
#include "actor/Player/Status.h"
#include "attack/KnockBack.h"
#include "state/enemy/EnemyAIController.h"
#include "IEnemy.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;

class Goblin :public IEnemy
{
public://Actor�p��&�R���X�g���N�^
	Goblin(const Transform& _transform, EnemyMediator& _mediator);
	~Goblin();
	void initialize() override;//actor
	void update(float deltatime)override;//actor
	void draw(IRenderer* _renderer)override;//actor
	/**
	* @brief �_���[�W�X�e�[�g�ɐ؂�ւ�HP���}�C�i�X
	* @param (&_attackStatus) Player�̃X�e�[�^�X
	*/
	void damage(const AttackStatus& _attackStatus)override;
	/**
	*@breif ������ђl�ɉ����ăA�j���[�V�����ύX
	*@param[_blowPower]�H������U���̐�����ђl
	*/
	void blowDamageDecision(const GSvector3& _blowPower)override;
	void blowDown(const GSvector3& _blowPower);
private:
	/**
	* @brief state�����������
	*/
	void createStates()override;
	/**
	* @breif �v�l�֐�
	* @param[_player] �v���C���[�̃|�C���^
	*/
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
	class EDownState;


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
	friend EDownState;
};
