#pragma once

/**
* @file ComboAttack.h
* @brief コンボ攻撃用クラス
* @author 松尾裕也
* @date 2016/11/27
*/
#include <unordered_map>
#include <memory>
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
	//入力があったときによばれる
	const bool next(bool _isSlow);
	const bool isEnd()const;
	const AttackStatus &getStatus() const;
private:
	Player* m_player;
	Attack m_current;
	std::unordered_map<std::string, Attack> m_container;
	bool m_isEnd;
};
