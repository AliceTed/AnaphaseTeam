#pragma once

/**
* @file ComboAttack.h
* @brief コンボ攻撃用クラス
* @author 松尾裕也
* @date 2016/11/27

かなりひどい攻撃関係のクソース化と
設計の破綻があったので攻撃関係を全修正
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
	//入力があったときによばれる
	void next(bool _isSlow);
	//アニメーション終了時に呼ばれつ
	void change();
	const bool isEnd()const;
private:
	Player* m_player;
	Attack m_current;
	ATTACK_TYPE m_nextKey;
	std::unordered_map<ATTACK_TYPE, Attack> m_container;
	bool m_isEnd;
};
