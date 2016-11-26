/**
* @file attackControl.h
* @brief UŒ‚‚Ì§Œä
* @author ‹gŒ³‰ëŠì
* @date 2016/09/11
*/
#pragma once
#include "ComboManager.h"
class Player;
class AttackManager
{
public:
	AttackManager();
	~AttackManager();
	void initialize();
	void update(float deltaTime,Player* _player);
	const bool isEnd() const;
	void Start(bool _attackChange,Player* _player);
private:
	ComboManager m_combo;
};

