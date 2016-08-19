#pragma once
/**
* @file Animator.h
* @brief Animation��map��p���A�t�������ĊǗ�����
* 08/19�ǋL _A���t���Ă�֐����h�c������ꍇ�̊֐�
* @author �v�H
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
	/*mesh,anim,skl���ʂ̂h�c�ŊǗ�*/
	Animator(const MODEL_ID _modelID);
	/*�h�c���ʂ̏ꍇ*/
	Animator(const ANIMATION_ID _anim_ID,const SKELETON_ID _skelton_ID);
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
	@fn
	@breif ������Animation�N���X�̃|�C���^������ƌĂяo���������Ȃ�̂ő΍���
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

	/*���b�V���ƃA�j���[�V�����Ƃ��ʂ̏ꍇ�̕ϐ�*/

	const ANIMATION_ID m_anim_ID;
	const SKELETON_ID m_Skelton_ID;
	std::map<PLAYERACTION_ID, Animation_Ptr> m_animationsMap_ACTION;
	PLAYERACTION_ID m_currentAnimationID_ACTION;
};