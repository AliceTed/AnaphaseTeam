#pragma once
/**
* @file AttackStatus.h
* @brief �U���̃p�����[�^
* @author �����T��
* @date 2016/8/26
*/
#include <gslib.h>
class TestActor;
class Player;
class AttackStatus
{
public:
	AttackStatus(float _attackPower,float _distanceDecay,const GSvector3& _blowOffPower);
	~AttackStatus();

	//�З͂Ɛ�����т�n��
	void giveDamage(Player* _player,TestActor* _other);
private:
	//!�U����
	float m_Power;
	//!��������
	float m_DistanceDecay;
	//!������ђl(��肠�����x�N�^�[3�Ŏ���)
	GSvector3 m_BlowOff;
};

