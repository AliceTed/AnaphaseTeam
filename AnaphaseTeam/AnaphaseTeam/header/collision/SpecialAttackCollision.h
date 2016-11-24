#pragma once
#include "CollisionActor.h"
#include "../transform/Transform.h"
//***�@�\�m�F�p
#include <string>
//**

class Player;
class SpecialAttack;
class SpecialAttackCollision :public CollisionActor
{
public:
	SpecialAttackCollision(Player* _player, SpecialAttack* _specialAttack);
	~SpecialAttackCollision();
	void chase(const GSvector3& _position);
private:
	void doUpdate(float deltaTime)override;

	//�ȉ��ꎞ�I�ȃe�X�g�p
	void doDraw(IRenderer * _renderer)override;
private:
	Player* m_player;
	SpecialAttack* m_specialAttack;
	//****
	std::string m_text;
};