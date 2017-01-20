/**
* @file IEnemy.cpp
* @brief �{�X�N���X
* @author �v�H
* @date 2017/01/16
�{�X�̓����E�d�l
�S�u�������傫��
�ϋv�͂�����
�ϋv�͂����ȉ��ɂȂ�ƃ��f����ς��āA�s���p�^�[�����ς��
*/
#include "actor/Boss/Boss.h"

Boss::Boss(const Transform & _transform, EnemyMediator & _mediator)
	:IEnemy(_transform, MODEL_ID::ENEMY, _mediator,Actor_Tag::BOSS)
{
}

Boss::~Boss()
{
}

void Boss::initialize()
{
}

void Boss::update(float deltatime)
{
}

void Boss::draw(const IRenderer & _renderer)
{
}

void Boss::damage(const AttackStatus & _attackStatus)
{
}

void Boss::think(Player * _palyer)
{
}

void Boss::createStates()
{
}