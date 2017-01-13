/**
* @file Status.h
* @brief プレイヤーのステータス計算用クラス
* @author Ruri
* @date 2016.9.23
*/

#pragma once

#include "StatusParameter.h"

class Gauge;

class Status
{
public:
	Status(const StatusParameter& _parameter);
	~Status();
	void initialize();
	void change(Gauge& _gauge); 
	float attackSpeed() const;
	float getHp();
	const float getMaxHp()const;
	void down(float _damage);
	void add(float _amount);
public:
	StatusParameter m_parameter;
	float m_hp;
	float m_maxHp;
	float m_AttackSpeed;
	const float def;
};