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
	* @fn
	* @breif 引数にAnimationクラスのポインタを入れると呼び出し時長くなるので対策版
	* @param (_animationKey) ANIMATION_IDでキーと登録するアニメーション
	* @param (_animationspeed) アニメーションのスピード（デフォルト＝1.0f）
	* @param (_isLoop) ループするか否か（デフォルトではループしない）
	*/
	void addAnimation(ANIMATION_ID _animationKey, float _animationspeed = 1.0f, bool _isLoop = false);
	void update(float deltatime);
	void bind()const;
	/**
	* @fn
	* @breif アニメーションの切り替え
	* @param (_nextAnimationID) 切り替え先のアニメーションのID
	* @param (_isNotInit) 切り替えた時にリセットしないか否か（デフォルトはリセットする）
	*/
	void changeAnimation(ANIMATION_ID _nextAnimationID, bool _isNotInit = false);
	/**
	* @fn
	* @breif 今動いているアニメーションが終わっているか
	*/
	bool isEndCurrentAnimation();
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
	std::map<ANIMATION_ID, Animation_Ptr> m_animationsMap;
};