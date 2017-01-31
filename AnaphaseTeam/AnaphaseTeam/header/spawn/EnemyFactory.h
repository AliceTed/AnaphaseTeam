#pragma once
#include "actor\Enemy\Goblin.h"
#include "actor\Boss\Boss.h"
#include "transform\Transform.h"
#include "actor\Enemy\ENEMY_TYPE.h"
#include<memory>
class EnemyMediator;
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	const std::shared_ptr<IEnemy> createEnemy(Transform& _transform, EnemyMediator& _mediator,ENEMY_TYPE _type)const;
};