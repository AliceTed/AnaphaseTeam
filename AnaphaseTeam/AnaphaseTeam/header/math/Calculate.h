#ifndef _CALCULATE_H_
#define _CALCULATE_H_
/**
* @file Calculate.h
* @brief �v�Z�p�֐��I�u�W�F�N�g�Q
* @author �����T��
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
		* @brief �w�萔�Ń��[�v����
		* @param (_x) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail x��low�܂ŉ������hight��,hight�܂ŏオ���low�Ƀ��[�v
		*/
		template<class T>
		const T operator ()(const T _x, const T _low, const T _hight)const
		{
			const T n = std::fmod(_x - _low, _hight - _low);
			return (n >= 0) ? (n + _low) : (n + _hight);
		}

		/**
		* @fn
		* @brief vector2�p�̃��[�v
		* @param (_value) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail value��low�܂ŉ������hight��,hight�܂ŏオ���low�ɗv�f���ƂɃ��[�v
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
		* @brief vector3�p�̃��[�v
		* @param (_value) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail value��low�܂ŉ������hight��,hight�܂ŏオ���low�ɗv�f���ƂɃ��[�v
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
		* @brief �w�萔�ŃN�����v����
		* @param (_x) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail x��low�܂ŏオ���low��,hight�܂ŏオ���hight�ɐ���
		*/
		template<class T>
		const T operator ()(const T _x, const T _low, const T _hight)const
		{
			return std::min<T>(std::max<T>(_x, _low), _hight);
		}
		/**
		* @fn
		* @brief vector2�p�̃N�����v
		* @param (_x) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail x��low�܂ŏオ���low��,hight�܂ŏオ���hight�ɗv�f���Ɛ���
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
		* @brief vector3�p�̃N�����v
		* @param (_x) �m�F����l
		* @param (_low) �Œ�l
		* @param (_hight) �ő�l
		* @return �ύX�����l
		* @detail x��low�܂ŏオ���low��,hight�܂ŏオ���hight�ɗv�f���Ɛ���
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
		* @brief degree(�x)��radian(�ʓx)�ɕϊ�
		* @param (_x) �ϊ�����l
		* @return �ύX�����l
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
		* @brief radian(�ʓx)��degree(�x)�ɕϊ�
		* @param (_x) �ϊ�����l
		* @return �ύX�����l
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
		* @brief sin��degree(�x)�w��ōs��
		* @param (_deg) �ϊ�����l
		* @return �ύX�����l
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
		* @brief cos��degree(�x)�w��ōs��
		* @param (_deg) �ϊ�����l
		* @return �ύX�����l
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
		* @brief tan��degree(�x)�w��ōs��
		* @param (_deg) �ϊ�����l
		* @return �ύX�����l
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
		* @brief asin��degree(�x)�ŕԂ�
		* @param (_x) asin����l
		* @return degree�ɕύX�����l
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
		* @brief acos��degree(�x)�ŕԂ�
		* @param (_x) acos����l
		* @return degree�ɕύX�����l
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
		* @brief atan��degree(�x)�ŕԂ�
		* @param (_x) atan����l
		* @param (_y) atan����l
		* @return degree�ɕύX�����l
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
		* @brief �ׂ�����
		* @param (_start) �����ʒu
		* @param (_end) �I���ʒu
		* @param (_t)����
		* @param (_power) n��
		* @return ��Ԃ��Ă���l
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
		* @brief �ׂ���ƎO�p�֐��⊮
		* @param (_start) �����ʒu
		* @param (_end) �I���ʒu
		* @param (_t)����
		* @param (_power) n��
		* @return ��Ԃ��Ă���l
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
		* @brief �΂ˌv�Z
		* @param (_position)�ʒu
		* @param (_velocity)�ړ���
		* @param (_restPositio)�^�[�Q�b�g�̈ʒu
		* @param (_stiffness)�΂˂̋���
		* @param (_friction)���C��
		* @param (_mass)���g�̎���
		* @return �ʒu��Ԃ�
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
		* @brief �������v�Z
		* @param (_start)�����ʒu
		* @param (_v0)�����x
		* @param ( _time)����
		* @param (_gravity)�d��
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
		* @breif �������w��͈͓�������
		* @param[_value]���肷��l
		* @param[_upper]����l
		* @param[_lower]�����l
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