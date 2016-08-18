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
	Timer(float _end);
	~Timer();
	void initialize();
	void update(float _speed);
	const bool isEnd()const;

	void setEndTime(float _end);
	template<class Func>void accept(Func _func)
	{
		_func(m_Current);
	}
private:
	float m_Current;
	float m_End;
};
#endif