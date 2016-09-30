#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
#include "../data/ANIMATION_ID.h"
#include "../data/SKELETON_ID.h"
#include "../data/Model_ID.h"
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
	Animation(ANIMATION_ID _anim_id, SKELETON_ID _bone_id,T _animNo,AnimationTimer _timer, bool _isLoop=false)
		:m_isLoop(_isLoop), m_animNo(static_cast<unsigned int>(_animNo)), m_timer(_timer),
		m_anim_id(static_cast<unsigned int>(_anim_id)),m_bone_id(static_cast<unsigned int>(_bone_id))
	{

	}
	template<class T>
	Animation(MODEL_ID _code, T _animNo, AnimationTimer _timer, bool _isLoop = false)
		: m_isLoop(_isLoop), m_animNo(static_cast<unsigned int>(_animNo)), m_timer(_timer),
		m_anim_id(static_cast<unsigned int>(_code)), m_bone_id(static_cast<unsigned int>(_code))
	{

	}
	/*
	�A�j���[�V�����ԍ���uint�ŊǗ����Ă��ăL���X�g���K�v�Ȃ��Ƃ��p
	*/
	Animation(ANIMATION_ID _anim_id, SKELETON_ID _bone_id, unsigned int _animNo,
		AnimationTimer _timer, bool _isLoop = false);

	~Animation();
	void initialize();
	void update(float deltaTime);

	/*
	animator���ł�����{�[���̃{�[���̃o�C���h���A�j���[�^�Ɉړ�
	*/
	//void bind(GSuint anim_id);
	void bind()const;
	const bool getIsEnd()const;
	void stop();
	void start();
	unsigned int getAnimationNo();
	const float getSpeed() const;
	const float getcurrentTime() const;
private:
	void looping();

private:
	/*true�Ȃ烋�[�v*/
	bool m_isLoop;
	AnimationTimer m_timer;
	unsigned int m_animNo;

	unsigned int m_anim_id;
	unsigned int m_bone_id;
};

#endif