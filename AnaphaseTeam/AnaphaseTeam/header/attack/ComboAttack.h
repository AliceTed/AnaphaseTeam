#pragma once

/**
* @file ComboAttack.h
* @brief �R���{�U���p�N���X
* @author �����T��
* @date 2016/11/27

���Ȃ�Ђǂ��U���֌W�̃N�\�[�X����
�݌v�̔j�]���������̂ōU���֌W��S�C��
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
	//���͂��������Ƃ��ɂ�΂��
	void next(bool _isSlow);
	//�A�j���[�V�����I�����ɌĂ΂��
	void change();
	const bool isEnd()const;
private:
	Player* m_player;
	Attack m_current;
	ATTACK_TYPE m_nextKey;
	std::unordered_map<ATTACK_TYPE, Attack> m_container;
	bool m_isEnd;
};
