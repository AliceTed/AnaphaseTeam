/**
* @file attackControl.h
* @brief �U���̐���
* @author �g�����
* @date 2016/09/11
*/
#pragma once
#include "header\device\Input.h"
#include "Scythe.h"
#include "Gun.h"
class attackManager
{
public:
	attackManager();
	~attackManager();
	void initialize();
	void update();
	bool scytheAttack();
	bool gunAttack();

private:
	const Input* m_Input;
	Scythe m_Scythe;
	Gun m_Gun;

};

