#pragma once

/**
* @file ComboAttack.h
* @brief �R���{�U���p�N���X
* @author �����T��
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
	bool finish(Animator & _animator);
	//���͂��������Ƃ��ɂ�΂��
	const bool next(bool _isSlow);
	bool isAttack(Animator & _animator);
	const bool isEnd()const;
	const AttackStatus &getStatus() const;
	const bool isFinishAttack();
private:
	Player* m_player;
	Attack m_current;
	Attack m_prev;
	std::unordered_map<std::string, Attack> m_container;
	bool m_isEnd;
};
