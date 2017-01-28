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
	void draw(IRenderer* _renderer);
	void damage(const AttackStatus& _attackStatus)override;//actor
public:
	void think(Player* _palyer)override;
private:
	void createStates()override;

private:
	bool m_isDown;
private:
	class BStandState;
	friend BStandState;

	// IEnemy ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void blowDamageDecision(const GSvector3 & _blowPower) override;
	virtual void readStatus() override;
};