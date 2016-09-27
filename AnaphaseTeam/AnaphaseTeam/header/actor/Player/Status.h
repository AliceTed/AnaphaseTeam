/**
* @file Status.h
* @brief プレイヤーのステータス計算用クラス
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
	 * @brief 移動速度(走り)の値を計算して返す
	 * @return 移動速度(走り)
	 */
	const float getMoveSpeed(bool _leftLegFig, bool _rightLegFig);
	/**
	 * @brief 回転速度の値を計算して返す
	 * @return 回転速度
	 */
	const float getRotateSpeed();
	/**
	 * @brief 移動速度(歩き)の値を計算して返す
	 * @return 移動速度(歩き)
	 */
	const float getWalkSpeed();

	/**
	 * @brief ジャンプ力の値を計算して返す
	 * @return ジャンプ力
	 */
	const float getJumpPower(float _jumpPower);

	const int getHp();

	//
	void powerUp();
	void giveJumpPower(JumpControl* _control,float _scale);
	//
private:
	//! 移動速度(走り)代入用
	float m_moveSpeed;
	//! 回転速度代入用
	float m_rotateSpeed;
	//! 移動速度(歩き)代入用
	float m_walkSpeed;

	//! ジャンプ力
	float m_jumpPower;

	int m_hp;

	//
	//追加jump力
	float m_jumpower;
	//
private:
	//! 移動速度(走り)
	static const float MOVESPEED;
	//! 回転速度
	static const float ROTATESPEED;
	//! 移動速度(歩き)
	static const float WALKSPEED;
	//! ジャンプ力
	static const float JUMPPOWER;

};