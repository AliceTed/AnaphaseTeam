/**
 * @file Input.h
 * @brief ���͏����N���X
 * @author Ruri
 * @date 2016.8.11
 */

#pragma once

#include <gslib.h>

class Input
{
public:
	Input();
	~Input();
	/**
	 * @brief A�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerA() const;
	/**
	 * @brief B�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerB() const;
	/**
	 * @brief X�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerX() const;
	/**
	 * @brief Y�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerY() const;
	/**
	 * @brief LB�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerLB() const;
	/**
	 * @brief RB�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerRB() const;
	/**
	 * @brief BACK�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerBACK() const;
	/**
	 * @brief START�{�^���������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerSTART() const;
	/**
	 * @brief �����W���C�X�e�B�b�N���������܂ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerLeftThrust() const;
	/**
	 * @brief �E���W���C�X�e�B�b�N���������܂ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyTriggerRightThrust() const;
	/**
	 * @return XY�̌X��
	 * @detail �����W���C�X�e�B�b�N�̌X����GSvector2�ŕԂ�
	 */
	const GSvector2 leftPadAxis() const;
	/**
	 * @return XY�̌X��
	 * @detail �E���W���C�X�e�B�b�N�̌X����GSvector2�ŕԂ�
	 */
	const GSvector2 rightPadAxis() const;
	/**
	 * @brief ���g���K�[�������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyLeftTrigger();
	/**
	 * @brief �E�g���K�[�������ꂽ��
	 * @return �g���K�[����
	 */
	const bool isJoyRightTrigger();

private:
	//! 1�t���[���O�̍��g���K�[�̓��͏��
	bool m_previousLeftTrigger;
	//! 1�t���[���O�̉E�g���K�[�̓��͏��
	bool m_previousRightTrigger;

};