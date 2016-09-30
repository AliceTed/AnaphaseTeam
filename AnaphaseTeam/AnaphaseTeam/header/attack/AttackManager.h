/**
* @file attackControl.h
* @brief UŒ‚‚Ì§Œä
* @author ‹gŒ³‰ëŠì
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
	const bool isEnd() const;
private:
	Scythe m_Scythe;
	Gun m_Gun;
	ComboManager m_combo;
};

