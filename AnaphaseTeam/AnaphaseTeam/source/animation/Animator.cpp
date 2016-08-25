/**
* @file Animator.cpp
* @brief
* @author 久秋
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

void Animator::addAnimation(ANIMATION_ID _animationKey, float _animationtime, float _animationspeed, bool _isLoop)
{
	m_animationsMap[_animationKey] = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_animationKey), AnimationTimer(_animationtime, _animationspeed), _isLoop);
}
void Animator::update(float deltatime)
{
	m_animationsMap[m_currentAnimationID]->update(deltatime);
}
void Animator::bind()
{
	m_animationsMap[m_currentAnimationID]->bind();
	gsBindSkeleton(static_cast<GSuint>(m_modelID));

}
void Animator::changeAnimation(ANIMATION_ID _nextAnimationID, bool isInit)
{
	/*同じ物には変更しない*/
	if (m_currentAnimationID == _nextAnimationID) return;

	m_currentAnimationID = _nextAnimationID;
	if (isInit)return;
	m_animationsMap[m_currentAnimationID]->initialize();
}
