/**
* @file attackControl.h
* @brief UŒ‚‚Ì§Œä
* @author ‹gŒ³‰ëŠì
* @date 2016/09/11
*/
#pragma once
#include "../../device/Input.h"
#include "Scythe.h"
#include "Gun.h"
class Player;
class attackManager
{
public:
	attackManager();
	~attackManager();
	void initialize();
	void update(Player* _player);
	void scytheAttack(Player* _player);
private:
	const Input* m_Input;
	Scythe m_Scythe;
	Gun m_Gun;

};

