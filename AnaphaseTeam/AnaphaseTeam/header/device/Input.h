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
	 * @return トリガー判定
	 */
	const bool isJoyTriggerA() const;
	/**
	 * @brief Bボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerB() const;
	/**
	 * @brief Xボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerX() const;
	/**
	 * @brief Yボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerY() const;
	/**
	 * @brief LBボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerLB() const;
	/**
	 * @brief RBボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerRB() const;
	/**
	 * @brief BACKボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerBACK() const;
	/**
	 * @brief STARTボタンが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerSTART() const;
	/**
	 * @brief 左側ジョイスティックが押し込まれたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerLeftThrust() const;
	/**
	 * @brief 右側ジョイスティックが押し込まれたか
	 * @return トリガー判定
	 */
	const bool isJoyTriggerRightThrust() const;
	/**
	 * @return XYの傾き
	 * @detail 左側ジョイスティックの傾きをGSvector2で返す
	 */
	const GSvector2 leftPadAxis() const;
	/**
	 * @return XYの傾き
	 * @detail 右側ジョイスティックの傾きをGSvector2で返す
	 */
	const GSvector2 rightPadAxis() const;
	/**
	 * @brief 左トリガーが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyLeftTrigger();
	/**
	 * @brief 右トリガーが押されたか
	 * @return トリガー判定
	 */
	const bool isJoyRightTrigger();

private:
	//! 1フレーム前の左トリガーの入力状態
	bool m_previousLeftTrigger;
	//! 1フレーム前の右トリガーの入力状態
	bool m_previousRightTrigger;

};