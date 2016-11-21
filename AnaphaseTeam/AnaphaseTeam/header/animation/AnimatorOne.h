#pragma once
#pragma once
/**
* @file Animator.h
* @brief Animation��map��p���A�t�������ĊǗ�����
* @author �v�H
* @date 2016/08/16
* @date 2016/8/30�@isEndCurrentAnimation��isEndAnimation�ǉ��A�R�����g�L��
*/
#include<gslib.h>
#include "../data/Model_ID.h"
#include <memory>
#include "Animation.h"
#include <vector>
#include "../data/CastID.h"
#include "../../header/transform/Transform.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class Renderer;
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
	/*mesh,anim,skl���ʂ̂h�c�ŊǗ�*/
	AnimatorOne(const MODEL_ID _modelID);
	~AnimatorOne();
	void initialize();
	void update(float deltatime);
	void changeAnimationLerp(unsigned int _animation);
	void changeAnimationLerp(unsigned int _animation,float _animSpeed);
	void changeAnimation(unsigned int _animation, bool _isLerp = true, bool _isLoop = false, bool _isNotInit = false,float _lerpTime=10.0f, float _animationSpeed = 1.0f);

	/**
	* @fn
	* @breif �������Ă���A�j���[�V�������I����Ă��邩
	*/
	const bool isEndCurrentAnimation() const;
	void lerpBegin(unsigned int _anim, bool _init=false, bool _loop=false,float _lerpTime=10.0f, float _animSpeed=1.0f);
	/*
	@fn �A�j���[�V�����s��̌v�Z
	*/
	void animationCaluculate(GSmatrix4* _animMat);
	void animationCaluculateLerp(GSmatrix4* _animMat);
	void draw(const Renderer& _renderer, const Transform& _transform, const GScolor& _color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));
	const GSmatrix4 & getOrientedMat(unsigned int index)const;
	const float getCurrentAnimationTime()const;
	const float getCurrentAnimationEndTime()const;

	const float getNextAnimationTime()const;
	const float getNextAnimationEndTime()const;
private:
	void matrixCalculate();
	void skeltonCalculateTransform(GSmatrix4* _mat);
	void change(Animation_Ptr _next);
private:

	const MODEL_ID m_modelID;
	Animation_Ptr m_currentAnimation;
	Animation_Ptr m_nextAnimation;
	static const unsigned int BONELENGTH=256;
	LerpData m_lerpData;
	//std::shared_ptr<GSmatrix4> m_matPtr;
	std::shared_ptr<GSmatrix4>  m_orientedMat;
};