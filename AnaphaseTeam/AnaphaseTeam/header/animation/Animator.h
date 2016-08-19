#pragma once
/**
* @file Animator.h
* @brief Animationをmapを用い、付けかえて管理する
* 08/19追記 _Aが付いてる関数がＩＤ分ける場合の関数
* @author 久秋
* @date 2016/08/16
*/
#include "../data/Model_ID.h"
#include "../data/SKELETON_ID.h"
#include "../data/ANIMATION_ID.h"
#include "../data/PLAYERACTION_ID.h"
#include <map>
#include <memory>
#include "Animation.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class Animator
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	Animator(const MODEL_ID _modelID);
	/*ＩＤが別の場合*/
	Animator(const ANIMATION_ID _anim_ID,const SKELETON_ID _skelton_ID);
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
	void addAnimation_A(PLAYERACTION_ID _animationKey, bool _isLoop=false);
	void update(float deltatime);
	void update_A(float deltatime);
	void bind();
	void bind_A();
	void changeAnimation(ANIMATION_ID _nextAnimationID, bool _isInit = false);
	void changeAnimation_A(PLAYERACTION_ID _nextAnimationID, bool isInit);
private:
	const MODEL_ID m_modelID;
	ANIMATION_ID m_currentAnimationID;
	std::map<ANIMATION_ID, Animation_Ptr> m_animationsMap;

	/*メッシュとアニメーションとか別の場合の変数*/

	const ANIMATION_ID m_anim_ID;
	const SKELETON_ID m_Skelton_ID;
	std::map<PLAYERACTION_ID, Animation_Ptr> m_animationsMap_ACTION;
	PLAYERACTION_ID m_currentAnimationID_ACTION;
};