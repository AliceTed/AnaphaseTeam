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
	 */
	const bool isJoyTriggerA() const;
	/**
	 * @brief B�{�^���������ꂽ��
	 */
	const bool isJoyTriggerB() const;
	/**
	 * @brief X�{�^���������ꂽ��
	 */
	const bool isJoyTriggerX() const;
	/**
	 * @brief Y�{�^���������ꂽ��
	 */
	const bool isJoyTriggerY() const;
	/**
	 * @brief LB�{�^���������ꂽ��
	 */
	const bool isJoyTriggerLB() const;
	/**
	 * @brief RB�{�^���������ꂽ��
	 */
	const bool isJoyTriggerRB() const;
	/**
	 * @brief BACK�{�^���������ꂽ��
	 */
	const bool isJoyTriggerBACK() const;
	/**
	 * @brief START�{�^���������ꂽ��
	 */
	const bool isJoyTriggerSTART() const;
	/**
	 * @brief ���W���C�X�e�B�b�N���������܂ꂽ��
	 */
	const bool isJoyTriggerLeftThrust() const;
	/**
	 * @brief �E�W���C�X�e�B�b�N���������܂ꂽ��
	 */
	const bool isJoyTriggerRightThrust() const;
	/**
	 * @return GSvector2
	 * @detail ���W���C�X�e�B�b�N�̌X����GSvector2�ŕԂ�
	 */
	const GSvector2 leftPadAxis() const;
	/**
	 * @return GSvector2
	 * @detail �E�W���C�X�e�B�b�N�̌X����GSvector2�ŕԂ�
	 */
	const GSvector2 rightPadAxis() const;

};