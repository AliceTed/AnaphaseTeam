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
	//void bind()const;
	void changeAnimationLerp(unsigned int _animation);
	void changeAnimation(unsigned int _animation, bool _isLerp = true, bool _isLoop = false, bool _isNotInit = false,float _lerpTime=10.0f, float _animationSpeed = 1.0f);

	void change(Animation_Ptr _next);
	/**
	* @fn
	* @breif �������Ă���A�j���[�V�������I����Ă��邩
	*/
	const bool isEndCurrentAnimation() const;
	/**
	* @fn
	* @breif �w�肵���A�j���[�V�������I����Ă��邩
	* @param (_nextAnimationID) ���ׂ����A�j���[�V������ID
	* @detail �w�肵�����̂����쒆�̃A�j���[�V�����ƈႯ���True��Ԃ�
	*/
	//bool isEndAnimation(unsigned int _animationID);
	
	void lerpBegin(unsigned int _anim, bool _init=false, bool _loop=false,float _lerpTime=10.0f, float _animSpeed=1.0f);
	/*
	@fn �A�j���[�V�����s��̌v�Z
	*/
	void animationCaluculate(GSmatrix4* _animMat);
	void animationCaluculateLerp(GSmatrix4* _animMat);
	//void matrixCalculate(GSmatrix4* _reslut);
	void matrixCalculate();

	void draw(const Renderer& _renderer, const Transform& _transform, const GScolor& _color = GScolor(1.0f, 1.0f, 1.0f, 1.0f)) ;
	//const GSuint getNumBones()const;
	//const GSmatrix4 & getMat(unsigned int index) const;
	const GSmatrix4 & getOrientedMat(unsigned int index)const;
	const float getCurrentAnimationTime()const;
	const float getCurrentAnimationEndTime()const;
private:
	void skeltonCalculateTransform(GSmatrix4* _mat);

private:

	const MODEL_ID m_modelID;
	Animation_Ptr m_currentAnimation;
	Animation_Ptr m_nextAnimation;
	static const unsigned int BONELENGTH=256;
	LerpData m_lerpData;
	//std::shared_ptr<GSmatrix4> m_matPtr;
	std::shared_ptr<GSmatrix4>  m_orientedMat;
};