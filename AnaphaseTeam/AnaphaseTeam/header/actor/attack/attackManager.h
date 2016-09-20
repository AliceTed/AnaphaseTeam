/**
* @file attackControl.h
* @brief UŒ‚‚Ì§Œä
* @author ‹gŒ³‰ëŠì
* @date 2016/09/11
*/
#pragma once
#include "../../device/Input.h"
#include "ContinuationCombo.h"
#include "Scythe.h"
#include "Gun.h"
#include "AttackPattern.h"
#include <unordered_map>


typedef std::shared_ptr<Shape> Shape_Ptr;
class Player;
class AttackManager
{
public:
	AttackManager();
	~AttackManager();
	void initialize();
	void update(Player* _player);
	void scytheAttack(Player* _player);
	void gunAttack(Player* _player);
	bool isEndAttack(Animator * _animator);
private:
	const Input* m_Input;
	Scythe m_Scythe;
	Gun m_Gun;
	AttackPattern m_currentKey;
	std::unordered_map<AttackPattern, ContinuationCombo> m_Pattern;

};

