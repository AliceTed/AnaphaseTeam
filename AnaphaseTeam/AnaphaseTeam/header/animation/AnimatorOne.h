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
#include "../data/id/Model_ID.h"
#include <memory>
#include "Animation.h"
#include <vector>
#include "../data/id/CastID.h"
#include "../../header/transform/Transform.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class IRenderer;
struct LerpData
{
public:
	LerpData()
		:m_time(0.0f), m_lerpTime(10.0f)
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
		return m_time >= m_lerpTime;
	}

public:
	unsigned int m_currentID;
	unsigned int m_nextID;
	float m_lerpTime;
	float m_time;
	float m_startTime;
	float m_endTime;
	bool m_nextInit;
};

class Animator
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	Animator(const MODEL_ID _modelID);
	~Animator();
	void initialize();
	void update(float deltatime);
	template<class T>
	void changeAnimationLerp(T _animation)
	{
		changeAnimation(static_cast<GSuint>(_animation), true, false, false, 10.0f, 1.0f);
	}
	template<class T>
	void changeAnimationLerp(T _animation, float _animSpeed)
	{
		changeAnimation(static_cast<GSuint>(_animation), true, false, false, 10.0f, _animSpeed);
	}
	void changeAnimation(unsigned int _animation, bool _isLerp = true, bool _isLoop = false, bool _isNotInit = false, float _lerpTime = 10.0f, float _animationSpeed = 1.0f);
	template<class T>
	void changeAnimation(T _animation, bool _isLerp = true, bool _isLoop = false, bool _isNotInit = false, float _lerpTime = 10.0f, float _animationSpeed = 1.0f)
	{
		changeAnimation(static_cast<GSuint>(_animation), _isLerp, _isLoop, _isNotInit, _lerpTime, _animationSpeed);
	}

	/**
	* @fn
	* @breif 今動いているアニメーションが終わっているか
	*/
	const bool isEndCurrentAnimation() const;
	void lerpBegin(unsigned int _anim, bool _init = false, bool _loop = false, float _lerpTime = 10.0f, float _animSpeed = 1.0f);
	void begin(unsigned int _anim1, unsigned int _anim2, bool _init, bool _loop, float _lerpTime, float _animSpeed);
	/*
	@fn アニメーション行列の計算
	*/
	void animationCaluculate(GSmatrix4* _animMat);
	void animationCaluculateLerp(GSmatrix4* _animMat);
	void draw(IRenderer * _renderer, const Transform& _transform, const GScolor& _color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));
	const GSmatrix4 & getOrientedMat(unsigned int index)const;
	const float getCurrentAnimationTime()const;
	const float getCurrentAnimationEndTime()const;

	const float getNextAnimationTime()const;
	const float getNextAnimationEndTime()const;
	const bool getNext() const;
	const unsigned int getCurrent() const;
private:
	void matrixCalculate();
	void skeltonCalculateTransform(GSmatrix4* _mat);
	void change(Animation_Ptr _next);
private:

	const MODEL_ID m_modelID;
	Animation_Ptr m_currentAnimation;
	Animation_Ptr m_nextAnimation;
	static const unsigned int BONELENGTH = 256;
	LerpData m_lerpData;
	//std::shared_ptr<GSmatrix4> m_matPtr;
	std::shared_ptr<GSmatrix4>  m_orientedMat;
};