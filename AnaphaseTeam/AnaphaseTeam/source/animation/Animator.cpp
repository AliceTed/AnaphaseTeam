/**
* @file Animator.cpp
* @brief
* @author ãvèH
* @date 2016/08/16
*/

#include "../../header/animation/Animator.h"
#include <gslib.h>
Animator::Animator(const ANIMATION_ID _anim_ID, const SKELETON_ID _skelton_ID)
	:m_modelID(), m_anim_ID(_anim_ID), m_Skelton_ID(_skelton_ID), m_currentAnimationID(),m_animationsMap_ACTION()
{
}
Animator::Animator(const MODEL_ID _modelID)
	: m_modelID(_modelID), m_anim_ID(), m_Skelton_ID(), m_currentAnimationID(),m_currentAnimationID_ACTION()
{
}
Animator::~Animator()
{
}
void Animator::initialize()
{
	m_animationsMap.clear();
	m_animationsMap_ACTION.clear();
}

void Animator::addAnimation(ANIMATION_ID _animationKey, Animation_Ptr _animation)
{
	m_animationsMap[_animationKey] = _animation;
}

void Animator::addAnimation(ANIMATION_ID _animationKey, float _animationtime, float _animationspeed, bool _isLoop)
{
	m_animationsMap[_animationKey] = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_animationKey), AnimationTimer(_animationtime, _animationspeed), _isLoop);
}
void Animator::addAnimation_A(PLAYERACTION_ID _animationKey, bool _isLoop)
{
	m_animationsMap_ACTION[_animationKey] = std::make_shared<Animation>(m_anim_ID, m_Skelton_ID, static_cast<unsigned int>(_animationKey), AnimationTimer(gsGetEndAnimationTime(static_cast<GSuint>(m_anim_ID), static_cast<unsigned int>(_animationKey))), _isLoop);
}
void Animator::update(float deltatime)
{
	m_animationsMap[m_currentAnimationID]->update(deltatime);
}
void Animator::update_A(float deltatime)
{
	m_animationsMap_ACTION[m_currentAnimationID_ACTION]->update(deltatime);
}
void Animator::bind()
{
	m_animationsMap[m_currentAnimationID]->bind();
	//gsBindSkeleton(static_cast<GSuint>(m_modelID));
	gsBindSkeleton(static_cast<GSuint>(m_Skelton_ID));
}
void Animator::bind_A()
{
	m_animationsMap_ACTION[m_currentAnimationID_ACTION]->bind();
	gsBindSkeleton(static_cast<GSuint>(m_Skelton_ID));
}
void Animator::changeAnimation(ANIMATION_ID _nextAnimationID, bool isInit)
{
	/*ìØÇ∂ï®Ç…ÇÕïœçXÇµÇ»Ç¢*/
	if (m_currentAnimationID == _nextAnimationID) return;

	m_currentAnimationID = _nextAnimationID;
	if (isInit)return;
	m_animationsMap[m_currentAnimationID]->initialize();
}
void Animator::changeAnimation_A(PLAYERACTION_ID _nextAnimationID, bool isInit)
{
	/*ìØÇ∂ï®Ç…ÇÕïœçXÇµÇ»Ç¢*/
	if (m_currentAnimationID_ACTION == _nextAnimationID) return;

	m_currentAnimationID_ACTION = _nextAnimationID;
	if (!isInit)return;
	m_animationsMap_ACTION[m_currentAnimationID_ACTION]->initialize();
}
