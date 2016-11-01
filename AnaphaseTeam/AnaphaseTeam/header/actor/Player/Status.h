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
	Status();
	~Status();
	void initialize();
	void change(Gauge& _gauge); 
	float attackSpeed();
private:
	float m_hp;
	float m_AttackSpeed;
	const float def ;
};