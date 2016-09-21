#pragma once
#pragma once
/**
* @file Animator.h
* @brief Animationをmapを用い、付けかえて管理する
* @author 久秋
* @date 2016/08/16
* @date 2016/8/30　isEndCurrentAnimationとisEndAnimation追加、コメント記入
*/
#include "../data/Model_ID.h"
#include <map>
#include <memory>
#include "Animation.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class AnimatorOne
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	AnimatorOne(const MODEL_ID _modelID);
	~AnimatorOne();
	void initialize();
	void update(float deltatime);
	void bind()const;
	void changeAnimation(ANIMATION_ID _animation, bool _isLoop=false, bool _isNotInit=false, float _animationSpeed = 1.0f);
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
private:
	const MODEL_ID m_modelID;
	ANIMATION_ID m_currentAnimationID;
	Animation_Ptr m_currentAnimation;
};