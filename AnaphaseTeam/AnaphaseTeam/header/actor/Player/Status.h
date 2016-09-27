/**
* @file Status.h
* @brief �v���C���[�̃X�e�[�^�X�v�Z�p�N���X
* @author Ruri
* @date 2016.9.23
*/

#pragma once

//
class JumpControl;
//
class Status
{
public:
	Status();
	~Status();
	/**
	 * @brief �ړ����x(����)�̒l���v�Z���ĕԂ�
	 * @return �ړ����x(����)
	 */
	const float getMoveSpeed(bool _leftLegFig, bool _rightLegFig);
	/**
	 * @brief ��]���x�̒l���v�Z���ĕԂ�
	 * @return ��]���x
	 */
	const float getRotateSpeed();
	/**
	 * @brief �ړ����x(����)�̒l���v�Z���ĕԂ�
	 * @return �ړ����x(����)
	 */
	const float getWalkSpeed();

	/**
	 * @brief �W�����v�͂̒l���v�Z���ĕԂ�
	 * @return �W�����v��
	 */
	const float getJumpPower(float _jumpPower);

	const int getHp();

	//
	void powerUp();
	void giveJumpPower(JumpControl* _control,float _scale);
	//
private:
	//! �ړ����x(����)����p
	float m_moveSpeed;
	//! ��]���x����p
	float m_rotateSpeed;
	//! �ړ����x(����)����p
	float m_walkSpeed;

	//! �W�����v��
	float m_jumpPower;

	int m_hp;

	//
	//�ǉ�jump��
	float m_jumpower;
	//
private:
	//! �ړ����x(����)
	static const float MOVESPEED;
	//! ��]���x
	static const float ROTATESPEED;
	//! �ړ����x(����)
	static const float WALKSPEED;
	//! �W�����v��
	static const float JUMPPOWER;

};