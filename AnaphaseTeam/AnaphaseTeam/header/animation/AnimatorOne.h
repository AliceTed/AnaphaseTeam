#pragma once
#pragma once
/**
* @file Animator.h
* @brief Animationをmapを用い、付けかえて管理する
* @author 久秋
* @date 2016/08/16
* @date 2016/8/30　isEndCurrentAnimationとisEndAnimation追加、コメント記入
*/
#include<gslib.h>
#include "../data/Model_ID.h"
#include <map>
#include <memory>
#include "Animation.h"
#include <vector>
#include "../data/CastID.h"
typedef std::shared_ptr<Animation> Animation_Ptr;

class LerpData
{
public:
	LerpData()
		:m_time(0.0f),m_lerpTime(10.0f)
	{
	}
	void timerUpdate()
	{
		m_time += 1.0f;
	}
	void timerInit() {
		m_time = 0.0f;
	}
	bool lerpEnd()
	{
		return m_time > m_lerpTime;
	}

public:
	float m_lerpTime;
	float m_time;
	float m_startTime;
	float m_endTime;
	bool m_nextInit;
};



class AnimatorOne
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	AnimatorOne(const MODEL_ID _modelID);
	~AnimatorOne();
	void initialize();
	void update(float deltatime);
	void bind()const;
	void changeAnimation(ANIMATION_ID _animation,  bool _isLerp=true,bool _isLoop = false, bool _isNotInit = false, float _animationSpeed = 1.0f);
	void change(Animation_Ptr _next);
	/**
	* @fn
	* @breif 今動いているアニメーションが終わっているか
	*/
	const bool isEndCurrentAnimation() const;
	/**
	* @fn
	* @breif 指定したアニメーションが終わっているか
	* @param (_nextAnimationID) 調べたいアニメーションのID
	* @detail 指定したものが動作中のアニメーションと違ければTrueを返す
	*/
	bool isEndAnimation(ANIMATION_ID _animationID);
	void lerpBegin(ANIMATION_ID _anim, bool _init=false, bool _loop=false, float _animSpeed=1.0f);
	/*
	@fn アニメーション行列の計算
	*/
	void animationCaluculate(GSmatrix4* _animMat);
	void animationCaluculateLerp(GSmatrix4* _animMat);
	//void matrixCalculate(GSmatrix4* _reslut);
	GSmatrix4 * matrixCalculate();
	const GSuint getNumBones()const;
	const GSmatrix4 * getMat() const;
	const std::vector<GSmatrix4> getMatrixVector() const;
	const float getCurrentAnimationTime()const;
	const float getCurrentAnimationEndTime()const;

private:

	const MODEL_ID m_modelID;
	Animation_Ptr m_currentAnimation;
	Animation_Ptr m_nextAnimation;
	static const unsigned int BONELENGTH=256;
	LerpData m_lerpData;
	std::getMatrixVector()<GSmatrix4> m_matPtr;
	std::vector<GSmatrix4> m_matrix;
};