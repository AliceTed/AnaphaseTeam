/**
* @file Animator.cpp
* @brief
* @author ãvèH
* @date 2016/08/16
*/

#include "../../header/animation/Animator.h"
#include <gslib.h>
Animator::Animator(const MODEL_ID _modelID)
	:m_modelID(_modelID), m_currentAnimationID()
{
}
Animator::~Animator()
{
}
void Animator::initialize()
{
	m_animationsMap.clear();
}

void Animator::addAnimation(ANIMATION_ID _animationKey, Animation_Ptr _animation)
{
	m_animationsMap[_animationKey] = _animation;
}

void Animator::addAnimation(ANIMATION_ID _animationKey, float _animationspeed, bool _isLoop)
{
	m_animationsMap[_animationKey] = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_animationKey), AnimationTimer(gsGetEndAnimationTime(static_cast<GSuint>(m_modelID),static_cast<GSuint>(_animationKey)), _animationspeed), _isLoop);
}
void Animator::update(float deltatime)
{
	m_animationsMap[m_currentAnimationID]->update(deltatime);
}
void Animator::bind()const
{
	m_animationsMap.at(m_currentAnimationID)->bind();
	gsBindSkeleton(static_cast<GSuint>(m_modelID));

}
void Animator::changeAnimation(ANIMATION_ID _nextAnimationID, bool isNotInit)
{
	/*ìØÇ∂ï®Ç…ÇÕïœçXÇµÇ»Ç¢*/
	if (m_currentAnimationID == _nextAnimationID) return;

	m_currentAnimationID = _nextAnimationID;
	if (isNotInit)return;
	m_animationsMap[m_currentAnimationID]->initialize();
}
