#pragma once
/**
* @file Animator.h
* @brief Animationをmapを用い、付けかえて管理する
* @author 久秋
* @date 2016/08/16
*/
#include "../data/Model_ID.h"
#include <map>
#include <memory>
#include "Animation.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class Animator
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	Animator(const MODEL_ID _modelID);
	~Animator();
	void initialize();
	/**
	 * @fn
	* @brief mapに登録する
	* @param (_animationKey) ANIMATION_IDでキー
	 * @param (_animation) Animationクラスのshared_Ptr
	*/
	void addAnimation(ANIMATION_ID _animationKey, Animation_Ptr _animation);
	/**
	@fn
	@breif 引数にAnimationクラスのポインタを入れると呼び出し時長くなるので対策版
	*/
	void addAnimation(ANIMATION_ID _animationKey, float _animationtime, float _animationspeed = 1.0f, bool _isLoop = false);
	void update(float deltatime);
	void bind();
	void changeAnimation(ANIMATION_ID _nextAnimationID, bool _isInit = false);
private:
	const MODEL_ID m_modelID;
	ANIMATION_ID currentAnimationID;
	std::map<ANIMATION_ID, Animation_Ptr> m_animationsMap;

};