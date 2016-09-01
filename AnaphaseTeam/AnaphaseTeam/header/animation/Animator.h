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
class Animator
{
public:
	/*mesh,anim,skl���ʂ̂h�c�ŊǗ�*/
	Animator(const MODEL_ID _modelID);
	~Animator();
	void initialize();
	/**
	* @fn
	* @brief map�ɓo�^����
	* @param (_animationKey) ANIMATION_ID�ŃL�[
	* @param (_animation) Animation�N���X��shared_Ptr
	*/
	void addAnimation(ANIMATION_ID _animationKey, Animation_Ptr _animation);
	/**
	* @fn
	* @breif ������Animation�N���X�̃|�C���^������ƌĂяo���������Ȃ�̂ő΍���
	* @param (_animationKey) ANIMATION_ID�ŃL�[�Ɠo�^����A�j���[�V����
	* @param (_animationspeed) �A�j���[�V�����̃X�s�[�h�i�f�t�H���g��1.0f�j
	* @param (_isLoop) ���[�v���邩�ۂ��i�f�t�H���g�ł̓��[�v���Ȃ��j
	*/
	void addAnimation(ANIMATION_ID _animationKey, float _animationspeed = 1.0f, bool _isLoop = false);
	void update(float deltatime);
	void bind()const;
	/**
	* @fn
	* @breif �A�j���[�V�����̐؂�ւ�
	* @param (_nextAnimationID) �؂�ւ���̃A�j���[�V������ID
	* @param (_isNotInit) �؂�ւ������Ƀ��Z�b�g���Ȃ����ۂ��i�f�t�H���g�̓��Z�b�g����j
	*/
	void changeAnimation(ANIMATION_ID _nextAnimationID, bool _isNotInit = false);
	/**
	* @fn
	* @breif �������Ă���A�j���[�V�������I����Ă��邩
	*/
	bool isEndCurrentAnimation();
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
	std::map<ANIMATION_ID, Animation_Ptr> m_animationsMap;
};