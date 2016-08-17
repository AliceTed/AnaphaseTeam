#pragma once
/**
* @file Animator.h
* @brief Animation��map��p���A�t�������ĊǗ�����
* @author �v�H
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
	@fn
	@breif ������Animation�N���X�̃|�C���^������ƌĂяo���������Ȃ�̂ő΍���
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