#pragma once

#include <vector>
#include <memory>
#include "../Actor.h"
#include <math.h>
#include "../../state/enemy/EnemyAIController.h"
#include  "../Enemy/IEnemy.h"
class EnemyMediator;
class IEnemyAI;
class EnemyCollision;
class Player;
class Boss : public IEnemy
{
public:
	Boss(const Transform& _transform, EnemyMediator& _mediator);
	~Boss();
	void initialize();
	void update(float deltatime);
	void draw(const IRenderer& _renderer);
	void damage(const AttackStatus& _attackStatus)override;//actor
public:
	void think(Player* _palyer)override;
private:
	void createStates()override;

private:

};