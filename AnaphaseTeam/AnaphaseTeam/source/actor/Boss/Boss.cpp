/**
* @file IEnemy.cpp
* @brief ボスクラス
* @author 久秋
* @date 2017/01/16
ボスの特徴・仕様
ゴブリンより大きい
耐久力も多い
耐久力が一定以下になるとモデルを変えて、行動パターンも変わる
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