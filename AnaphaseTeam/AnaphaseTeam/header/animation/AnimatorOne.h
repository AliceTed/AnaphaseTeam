#pragma once
#pragma once
/**
* @file Animator.h
* @brief Animation��map��p���A�t�������ĊǗ�����
* @author �v�H
* @date 2016/08/16
* @date 2016/8/30�@isEndCurrentAnimation��isEndAnimation�ǉ��A�R�����g�L��
*/
#include "../data/Model_ID.h"
#include <map>
#include <memory>
#include "Animation.h"
typedef std::shared_ptr<Animation> Animation_Ptr;
class AnimatorOne
{
public:
	/*mesh,anim,skl���ʂ̂h�c�ŊǗ�*/
	AnimatorOne(const MODEL_ID _modelID);
	~AnimatorOne();
	void initialize();
	void update(float deltatime);
	void bind()const;
	void changeAnimation(ANIMATION_ID _animation, bool _isLoop=false, bool _isNotInit=false, float _animationSpeed = 1.0f);
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
	bool isEndAnimation(ANIMATION_ID _animationID);
private:
	const MODEL_ID m_modelID;
	ANIMATION_ID m_currentAnimationID;
	Animation_Ptr m_currentAnimation;
};