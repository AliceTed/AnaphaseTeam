#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
#include "ANIMATION_ID.h"
#include "BONE_ID.h"
/*
animation���̊Ǘ�

�ԍ��ƃ^�C�}�[��
loop���ǂ����Ȃǂ̏�������
*/

class Animation
{
public:
	/*
	enum�ȂǂŃA�j���[�V�����̔ԍ����Ǘ����Ă�Ƃ��p
	*/
	template<class T>
	Animation(ANIMATION_ID anim_id, BONE_ID bone_id,T animNo,AnimationTimer timer, bool isLoop=false)
		:isLoop(isLoop), animNo(static_cast<unsigned int>(animNo)), timer(timer),
		anim_id(static_cast<unsigned int>(anim_id)),bone_id(static_cast<unsigned int>(bone_id))
	{

	}
	/*
	�A�j���[�V�����ԍ���uint�ŊǗ����Ă��ăL���X�g���K�v�Ȃ��Ƃ��p
	*/
	Animation(ANIMATION_ID anim_id, BONE_ID bone_id, unsigned int animNo,
		AnimationTimer timer, bool isLoop = false);

	~Animation();
	void initialize();
	void update(float deltaTime);

	/*
	animator���ł�����{�[���̃{�[���̃o�C���h���A�j���[�^�Ɉړ�
	*/
	//void bind(GSuint anim_id);
	void bind();
	const bool getIsEnd()const;
	void stop();
	void start();
private:
	void looping();

private:
	/*true�Ȃ烋�[�v*/
	bool isLoop;
	AnimationTimer timer;
	unsigned int animNo;

	unsigned int anim_id;
	unsigned int bone_id;
};

#endif