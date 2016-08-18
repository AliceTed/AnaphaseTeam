/**
 * @file Input.h
 * @brief 入力処理クラス
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
	 * @brief Aボタンが押されたか
	 */
	const bool isJoyTriggerA() const;
	/**
	 * @brief Bボタンが押されたか
	 */
	const bool isJoyTriggerB() const;
	/**
	 * @brief Xボタンが押されたか
	 */
	const bool isJoyTriggerX() const;
	/**
	 * @brief Yボタンが押されたか
	 */
	const bool isJoyTriggerY() const;
	/**
	 * @brief LBボタンが押されたか
	 */
	const bool isJoyTriggerLB() const;
	/**
	 * @brief RBボタンが押されたか
	 */
	const bool isJoyTriggerRB() const;
	/**
	 * @brief BACKボタンが押されたか
	 */
	const bool isJoyTriggerBACK() const;
	/**
	 * @brief STARTボタンが押されたか
	 */
	const bool isJoyTriggerSTART() const;
	/**
	 * @brief 左ジョイスティックが押し込まれたか
	 */
	const bool isJoyTriggerLeftThrust() const;
	/**
	 * @brief 右ジョイスティックが押し込まれたか
	 */
	const bool isJoyTriggerRightThrust() const;
	/**
	 * @return GSvector2
	 * @detail 左ジョイスティックの傾きをGSvector2で返す
	 */
	const GSvector2 leftPadAxis() const;
	/**
	 * @return GSvector2
	 * @detail 右ジョイスティックの傾きをGSvector2で返す
	 */
	const GSvector2 rightPadAxis() const;

};