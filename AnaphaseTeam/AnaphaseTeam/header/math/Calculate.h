#ifndef _CALCULATE_H_
#define _CALCULATE_H_
/**
* @file Calculate.h
* @brief 計算用関数オブジェクト群
* @author 松尾裕也
* @date 2016/8/03
*/
#include <iostream>
#include <algorithm>
#include <gslib.h>
#include <cmath>
namespace Math
{
	static const float PI = 3.14159265f;

	class Wrap
	{
	public:
		/**
		* @fn
		* @brief 指定数でワープする
		* @param (_x) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail xがlowまで下がるとhightに,hightまで上がるとlowにワープ
		*/
		template<class T>
		const T operator ()(const T _x, const T _low, const T _hight)const
		{
			const T n = std::fmod(_x - _low, _hight - _low);
			return (n >= 0) ? (n + _low) : (n + _hight);
		}

		/**
		* @fn
		* @brief vector2用のワープ
		* @param (_value) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail valueがlowまで下がるとhightに,hightまで上がるとlowに要素ごとにワープ
		*/
		const GSvector2 operator ()(const GSvector2& _value, const GSvector2& _low, const GSvector2& _hight)const
		{
			GSvector2 res(0, 0);
			Wrap wrap;
			res.x = wrap(_value.x, _low.x, _hight.x);
			res.y = wrap(_value.y, _low.y, _hight.y);
			return res;
		}

		/**
		* @fn
		* @brief vector3用のワープ
		* @param (_value) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail valueがlowまで下がるとhightに,hightまで上がるとlowに要素ごとにワープ
		*/
		const GSvector3 operator ()(const GSvector3& _value, const GSvector3& _low, const GSvector3& _hight)const
		{
			GSvector3 res(0, 0, 0);
			Wrap wrap;
			res.x = wrap(_value.x, _low.x, _hight.x);
			res.y = wrap(_value.y, _low.y, _hight.y);
			res.z = wrap(_value.z, _low.z, _hight.z);
			return res;
		}
	};

	class Clamp
	{
	public:
		/**
		* @fn
		* @brief 指定数でクランプする
		* @param (_x) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail xがlowまで上がるとlowに,hightまで上がるとhightに制限
		*/
		template<class T>
		const T operator ()(const T _x, const T _low, const T _hight)const
		{
			return std::min<T>(std::max<T>(_x, _low), _hight);
		}
		/**
		* @fn
		* @brief vector2用のクランプ
		* @param (_x) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail xがlowまで上がるとlowに,hightまで上がるとhightに要素ごと制限
		*/
		const GSvector2 operator ()(const GSvector2& value, const GSvector2& low, const GSvector2& hight)const
		{
			GSvector2 res(0, 0);
			gsVector2Maximize(&res, &value, &low);
			gsVector2Minimize(&res, &res, &hight);
			return res;
		}
		/**
		* @fn
		* @brief vector3用のクランプ
		* @param (_x) 確認する値
		* @param (_low) 最低値
		* @param (_hight) 最大値
		* @return 変更した値
		* @detail xがlowまで上がるとlowに,hightまで上がるとhightに要素ごと制限
		*/
		const GSvector3 operator ()(const GSvector3& value, const GSvector3& low, const GSvector3& hight)const
		{
			GSvector3 res(0, 0, 0);
			gsVector3Maximize(&res, &value, &low);
			gsVector3Minimize(&res, &res, &hight);
			return res;
		}
	};

	class DegToRad
	{
	public:
		/**
		* @fn
		* @brief degree(度)をradian(弧度)に変換
		* @param (_x) 変換する値
		* @return 変更した値
		*/
		template<class T>
		const T operator ()(T _deg)const
		{
			return _deg*(PI / 180.0f);
		}
	};

	class RadToDeg
	{
	public:
		/**
		* @fn
		* @brief radian(弧度)をdegree(度)に変換
		* @param (_x) 変換する値
		* @return 変更した値
		*/
		template<class T>
		const T operator ()(T _rad)const
		{
			return _rad * 180.0f / PI;
		}
	};

	class Sin
	{
	public:
		/**
		* @fn
		* @brief sinをdegree(度)指定で行う
		* @param (_deg) 変換する値
		* @return 変更した値
		*/
		template<class T>
		const T operator ()(T _deg)const
		{
			DegToRad dtr;
			return std::sin(dtr(_deg));
		}
	};

	class Cos
	{
	public:
		/**
		* @fn
		* @brief cosをdegree(度)指定で行う
		* @param (_deg) 変換する値
		* @return 変更した値
		*/
		template<class T>
		const T operator ()(T _deg)const
		{
			DegToRad dtr;
			return std::cos(dtr(_deg));
		}
	};

	class Tan
	{
	public:
		/**
		* @fn
		* @brief tanをdegree(度)指定で行う
		* @param (_deg) 変換する値
		* @return 変更した値
		*/
		template<class T>
		const T operator ()(T _deg)const
		{
			DegToRad dtr;
			return std::tan(dtr(_deg));
		}
	};

	class ASin
	{
	public:
		/**
		* @fn
		* @brief asinをdegree(度)で返す
		* @param (_x) asinする値
		* @return degreeに変更した値
		*/
		template<class T>
		const T operator ()(T _x)const
		{
			RadToDeg rtd;
			return rtd(std::asin(_x));
		}
	};

	class ACos
	{
	public:
		/**
		* @fn
		* @brief acosをdegree(度)で返す
		* @param (_x) acosする値
		* @return degreeに変更した値
		*/
		template<class T>
		const T operator ()(T _x)const
		{
			RadToDeg rtd;
			return rtd(std::acos(_x));
		}
	};

	class ATan
	{
	public:
		/**
		* @fn
		* @brief atanをdegree(度)で返す
		* @param (_x) atanする値
		* @param (_y) atanする値
		* @return degreeに変更した値
		*/
		template<class T>
		const T operator ()(T _x, T _y)const
		{
			RadToDeg rtd;
			return rtd(std::atan2(_y, _x));
		}
	};

	class Power
	{
	public:
		/**
		* @fn
		* @brief べき乗補間
		* @param (_start) 初期位置
		* @param (_end) 終了位置
		* @param (_t)時間
		* @param (_power) n乗
		* @return 補間している値
		*/
		const GSvector3 operator ()(const GSvector3& _start, const GSvector3& _end, float _t, float _power)const
		{
			GSvector3 result;
			gsVector3Lerp(&result, &_start, &_end, pow(_t, _power));
			return result;
		}
	};

	class SinPower
	{
	public:
		/**
		* @fn
		* @brief べき乗と三角関数補完
		* @param (_start) 初期位置
		* @param (_end) 終了位置
		* @param (_t)時間
		* @param (_power) n乗
		* @return 補間している値
		*/
		const GSvector3 operator ()(const GSvector3& start, const GSvector3& end, float t, float power)const
		{
			GSvector3 result;
			Sin sin;
			gsVector3Lerp(&result, &start, &end, pow(sin(90.0f*t), power));
			return result;
		}
	};

	class Spring
	{
	public:

		/**
		* @fn
		* @brief ばね計算
		* @param (_position)位置
		* @param (_velocity)移動量
		* @param (_restPositio)ターゲットの位置
		* @param (_stiffness)ばねの強さ
		* @param (_friction)摩擦力
		* @param (_mass)自身の質量
		* @return 位置を返す
		*/
		const GSvector3 operator ()
			(
				GSvector3* _position,
				GSvector3* _velocity,
				const GSvector3& _restPosition,
				float _stiffness,
				float _friction,
				float _mass
				)const
		{
			GSvector3 stretch = *_position - _restPosition;
			GSvector3 force = -_stiffness*stretch;
			GSvector3 acceleration = force / _mass;
			*_velocity = _friction*(*_velocity + acceleration);
			*_position += *_velocity;
			return *_position;
		}
	};

	class Parabola
	{
	public:
		/**
		* @fn
		* @brief 放物線計算
		* @param (_start)初期位置
		* @param (_v0)初速度
		* @param ( _time)時間
		* @param (_gravity)重力
		*/
		const GSvector3 operator ()(const GSvector3& _start, const GSvector3& _v0, float _time, float _gravity)const
		{
			GSvector3 vector = _v0*_time;
			vector.y = _v0.y*_time + 0.5f*_gravity*_time*_time;
			GSvector3 result = _start + vector;
			return result;
		}
	};


	class Range
	{
	public:
		/**
		* @breif 距離が指定範囲内か判定
		* @param[_value]判定する値
		* @param[_upper]上限値
		* @param[_lower]下限値
		* @author Hisaaki
		* @data 2017/01/16
		*/
		template<class T>
		const bool operator ()(T _value, T _lower, T _upper)
		{
			return _lower < _value&&_value <= _upper;
		}
		template<class T>
		const bool InRange(T _value, T _lower, T _upper)
		{
			return _lower < _value&&_value <= _upper;
		}
	};
}
#endif