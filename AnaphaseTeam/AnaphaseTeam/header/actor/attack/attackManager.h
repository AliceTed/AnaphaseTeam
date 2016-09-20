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
#include <unordered_map>

enum class AttackKey
{
	attack1,
	attack2
};

typedef std::shared_ptr<Shape> Shape_Ptr;
class Player;
class attackManager
{
public:
	attackManager();
	~attackManager();
	void initialize();
	void update(Player* _player);
	void scytheAttack(Player* _player);
	void gunAttack(Player* _player);
	bool isEndAttack(Animator * _animator);
private:
	const Input* m_Input;
	Scythe m_Scythe;
	Gun m_Gun;
	AttackKey m_currentKey;
	std::unordered_map<AttackKey, ContinuationCombo> m_attackMap;

};

