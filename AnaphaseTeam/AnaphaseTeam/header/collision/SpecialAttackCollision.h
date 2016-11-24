#pragma once
#include "CollisionActor.h"
#include "../transform/Transform.h"
//***機能確認用
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

	//以下一時的なテスト用
	void doDraw(IRenderer * _renderer)override;
private:
	Player* m_player;
	SpecialAttack* m_specialAttack;
	//****
	std::string m_text;
};