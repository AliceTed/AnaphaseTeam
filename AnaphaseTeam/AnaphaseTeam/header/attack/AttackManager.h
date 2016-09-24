/**
* @file attackControl.h
* @brief �U���̐���
* @author �g�����
* @date 2016/09/11
*/
#pragma once
#include "../device/Input.h"

#include "Scythe.h"
#include "Gun.h"
#include "ComboManager.h"
typedef std::shared_ptr<Shape> Shape_Ptr;
class Player;
class CollisionMediator;
class AttackManager
{
public:
	AttackManager();
	~AttackManager();
	void initialize();
	void update(float deltaTime,Player* _player);
	void scytheAttack(float deltaTime, Player* _player);
	void gunAttack(Player* _player);
	const bool isEndAttack(const AnimatorOne * _animator) const;
private:
	const Input* m_Input;
	Scythe m_Scythe;
	Gun m_Gun;
	ComboManager m_combo;
};

