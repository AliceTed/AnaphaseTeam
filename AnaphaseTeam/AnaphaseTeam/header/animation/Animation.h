#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
#include "ANIMATION_ID.h"
#include "BONE_ID.h"
/*
animation情報の管理

番号とタイマーと
loopかどうかなどの情報を持つ
*/

class Animation
{
public:
	/*
	enumなどでアニメーションの番号を管理してるとき用
	*/
	template<class T>
	Animation(ANIMATION_ID anim_id, BONE_ID bone_id,T animNo,AnimationTimer timer, bool isLoop=false)
		:isLoop(isLoop), animNo(static_cast<unsigned int>(animNo)), timer(timer),
		anim_id(static_cast<unsigned int>(anim_id)),bone_id(static_cast<unsigned int>(bone_id))
	{

	}
	/*
	アニメーション番号をuintで管理していてキャストが必要ないとき用
	*/
	Animation(ANIMATION_ID anim_id, BONE_ID bone_id, unsigned int animNo,
		AnimationTimer timer, bool isLoop = false);

	~Animation();
	void initialize();
	void update(float deltaTime);

	/*
	animatorができ次第ボーンのボーンのバインドをアニメータに移動
	*/
	//void bind(GSuint anim_id);
	void bind();
	const bool getIsEnd()const;
	void stop();
	void start();
private:
	void looping();

private:
	/*trueならループ*/
	bool isLoop;
	AnimationTimer timer;
	unsigned int animNo;

	unsigned int anim_id;
	unsigned int bone_id;
};

#endif