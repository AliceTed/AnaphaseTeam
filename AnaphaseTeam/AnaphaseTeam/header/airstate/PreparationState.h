/**
* @file firstStep.h
* @brief ジャンプの準備ステート
* @author 渋谷知樹
* @date 2016/09/21
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class PreparationState :public IAirState
{
public:
	PreparationState(JumpControl* _control, Player* _player);
	~PreparationState();
	/**
	* @fn
	* @brief 
	*/
	void start();
	/**
	* @fn
	* @brief 
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	bool m_isEnd;
	AirAction_Ptr m_next;
	JumpControl* m_control;
	Player* m_player;
};