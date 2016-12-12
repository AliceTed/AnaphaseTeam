#pragma once
/**
* @file ContinuationCombo.h
* @brief 連続コンボ用単発攻撃
* @author 松尾裕也
* @date 2016/8/26
*/
#include "../data/id/ANIMATION_ID.h"
#include "AttackParameter.h"
#include "../convenient/Timer.h"
class Player;
class CollisionMediator;
class AnimatorOne;

class Attack
{
public:
	Attack(const AttackParameter& _paramerer);
	~Attack();
	void initialize(Player * _player);
	void update(float deltaTime,Player* _player);

	void motion(Player* _player);
	void changeMotion(AnimatorOne& _animator, float _speed);
	const std::string& next(bool _isSlow) const;
	const AttackStatus &getStatus() const; 
private:
	//!攻撃用Parameter
	AttackParameter m_parameter;
	Timer m_spawnTimer;
	bool isSpawn;
};