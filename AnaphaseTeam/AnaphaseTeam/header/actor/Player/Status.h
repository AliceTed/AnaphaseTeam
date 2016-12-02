/**
* @file Status.h
* @brief プレイヤーのステータス計算用クラス
* @author Ruri
* @date 2016.9.23
*/

#pragma once
class Gauge;
class Status
{
public:
	Status(float _hp = 100);
	~Status();
	void initialize();
	void change(Gauge& _gauge); 
	float attackSpeed();
	float getHp();
	void down(float _damage);
	void add();
private:
	float m_hp;
	const float m_defHp;
	float m_AttackSpeed;
	const float def ;
};