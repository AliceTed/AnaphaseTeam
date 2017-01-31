#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_
/**
* @file Tiemr.h
* @brief timer
* @author ¼”ö—T–ç
* @date 2016/8/18
*/
class Timer
{
public:
	Timer(float _end/*second*/);
	~Timer();
	void initialize();
	void update(float _speed);
	const bool isEnd()const;
	float rate()const;
	void setEndTime(float _end/*second*/);
	//Œ»İ‚ÌŠÔ‚ÆI—¹ŠÔ‚ğƒ~ƒŠ•b‚Å“n‚·
	template<class Func>void accept(Func _func)
	{
		_func(m_Current, m_End);
	}
private:
	float m_Current;
	float m_End;
	static const float FLAMETIME;
};
#endif