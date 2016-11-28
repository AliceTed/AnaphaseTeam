#pragma once

/**
* @file ComboAttack.h
* @brief ƒRƒ“ƒ{UŒ‚—pƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/11/27

‚©‚È‚è‚Ğ‚Ç‚¢UŒ‚ŠÖŒW‚ÌƒNƒ\[ƒX‰»‚Æ
İŒv‚Ì”j’]‚ª‚ ‚Á‚½‚Ì‚ÅUŒ‚ŠÖŒW‚ğ‘SC³
*/
#include <unordered_map>
#include <memory>
#include "ATTACK_TYPE.h"
#include "Attack.h"
class Player;
class ComboAttack
{
public:
	ComboAttack(Player* _player);
	~ComboAttack() = default;
	void initialize();
	void start(bool _isSlow);
	void update(float deltaTime);
	//“ü—Í‚ª‚ ‚Á‚½‚Æ‚«‚É‚æ‚Î‚ê‚é
	const bool next(bool _isSlow);
	const bool isEnd()const;
private:
	Player* m_player;
	Attack m_current;
	std::unordered_map<ATTACK_TYPE, Attack> m_container;
	bool m_isEnd;
};
