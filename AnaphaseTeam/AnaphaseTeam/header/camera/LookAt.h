/************************************************************
@file LookAt.h
@brief カメラの位置情報
@author Yuuho Aritomi
@date 2016/11/20
************************************************************/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	/********************************************************
	@brief コンストラクタ
	********************************************************/
	LookAt(void);



	/********************************************************
	@brief コンストラクタ
	@param[_position]	位置
	@param[_target]		注視点
	@param[_up]			カメラの上方向
	********************************************************/
	LookAt(
		const GSvector3& _position, 
		const GSvector3& _target, 
		const GSvector3& _up
	);



	/********************************************************
	@brief デストラクタ
	********************************************************/
	~LookAt();



	/********************************************************
	@brief 初期化
	@param[_position]	位置
	@param[_target]		注視点
	@param[_up]			カメラの上方向
	********************************************************/
	void initialize(
		const GSvector3& _position,
		const GSvector3& _target,
		const GSvector3& _up
	);



	/********************************************************
	@brief 更新処理
	********************************************************/
	void update(void);



	/********************************************************
	@brief 移動処理
	@param[_position] 移動先
	********************************************************/
	void set_position(const GSvector3& _position);



	/********************************************************
	@brief 平行移動
	@param[_vector] 移動量
	********************************************************/
	void translate(const GSvector3& _vector);



	/********************************************************
	@brief 被写体を見る
	@param[_target] ターゲット
	********************************************************/
	void lookAt(const GSvector3& _target);



	/********************************************************
	@brief オフセットを含めて被写体を見る
	@param[_target] ターゲット
	********************************************************/
	void lookAt_offset(const GSvector3& _target);



	/********************************************************
	@brief ｘ軸回転のみで被写体を見る
	@param[_target] ターゲット
	@param[_direction] 方位角
	********************************************************/
	void lookAt_tilt(const GSvector3& _target, const float _direction);



	/********************************************************
	@brief	ティルトカメラワーク
			x軸回転のみで被写体を見る
			（もっと簡単にしたいよ）
	@param[_position_camera]	カメラの位置
	@param[_position_target]	ターゲットの位置
	@param[_direction]			方位角
	@param[_followSpeed_camera] カメラの追尾速度
	@param[_followSpeed_target]	ターゲットの追尾速度
								[0] 追尾無し
								[0.1~0.9] ディレイありの追尾
								[1] 完全追尾
	********************************************************/
	void cameraWork_tilt(
		const GSvector3& _position_camera,
		const GSvector3& _position_target,
		const float _direction,
		const float _followSpeed_camera,
		const float _followSpeed_target
	);



	/********************************************************
	@brief y軸回転のみで被写体を見る
	@param[_target]		ターゲット
	@param[_elevation]	仰角
	********************************************************/
	void lookAt_pan(const GSvector3& _target, const float _elevation);



	/********************************************************
	@brief 被写体を見るかつついていく
	@param[_target]		ターゲット
	@param[_elevation]	仰角
	@param[_direction]	方位角
	@param[_distance]	距離
	********************************************************/
	void lookAt_dolly(
		const GSvector3&	_target, 
		const float			_elevation, 
		const float			_direction,
		const float			_distance
	);



	/********************************************************
	@brief 
	カメラの位置からターゲットの位置までの
	仰角、方位角を求める
	@param[_elevation] 仰角
	@param[_direction] 方位角
	********************************************************/
	void to_eleDir(float* _elevation, float* _direction);



	/********************************************************
	@brief カメラがターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
					[0] 追尾無し
					[1] ディレイありの追尾
					[2] 完全追尾
	********************************************************/
	void follow_position(const GSvector3& _target, const float _speed);



	/********************************************************
	@brief 注視点がターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
					[0] 追尾無し
					[1] ディレイありの追尾
					[2] 完全追尾
	********************************************************/
	void follow_target(const GSvector3& _target, const float _speed);



	/********************************************************
	@return 位置
	********************************************************/
	const GSvector3& position(void) const
	{
		return m_position;
	}
	/********************************************************
	@return ターゲット
	********************************************************/
	const GSvector3& target(void) const
	{
		return m_target;
	}
	/********************************************************
	@return カメラの上方向
	********************************************************/
	const GSvector3& up(void) const
	{
		return m_up;
	}
	/********************************************************
	@return モデルビュー行列
	********************************************************/
	const GSmatrix4& matView(void) const
	{
		return m_matView;
	}
	/********************************************************
	@return 仰角
	********************************************************/
	const float elevation(void) const
	{
		return m_elevation;
	}
	/********************************************************
	@return 方位角
	********************************************************/
	const float direction(void) const
	{
		return m_direction;
	}

	private:
		void to_radEleDir(float* _elevation, float * _direction);

		void vector_p1_p2(
			GSvector3*			_vector, 
			const GSvector3&	_p1, 
			const GSvector3&	_p2
		);

	private:
		GSvector3	m_position;
		GSvector3	m_target;
		GSvector3	m_targetOffset;
		GSvector3	m_up;

		GSmatrix4	m_matView;

		float		m_elevation;
		float		m_direction;
};
