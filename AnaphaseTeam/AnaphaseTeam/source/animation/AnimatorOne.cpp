#include "../../header/animation/AnimatorOne.h"
#include <gslib.h>
AnimatorOne::AnimatorOne(const MODEL_ID _modelID) :
	m_modelID(_modelID), m_currentAnimation(nullptr)
{}
AnimatorOne::~AnimatorOne()
{}
void AnimatorOne::initialize()
{

}
void AnimatorOne::update(float deltatime)
{
	if (m_currentAnimation == nullptr)
		return;

	m_currentAnimation->update(deltatime);
}
void AnimatorOne::bind()const
{
	m_currentAnimation->bind();
	gsBindSkeleton(static_cast<GSuint>(m_modelID));
}
void AnimatorOne::changeAnimation(ANIMATION_ID _animation, bool _isLoop, bool _isNotInit, float _animationSpeed)
{
	if (m_currentAnimation == nullptr)
		m_currentAnimation = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_animation), AnimationTimer(gsGetEndAnimationTime(static_cast<GSuint>(m_modelID), static_cast<GSuint>(_animation)), _animationSpeed), _isLoop);
	/*今のアニメーションと同じなら変えない*/
	if (m_currentAnimation->getAnimationNo() == static_cast<unsigned int>(_animation) && _animationSpeed == m_currentAnimation->getSpeed())
		return;

	m_currentAnimation = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_animation), AnimationTimer(gsGetEndAnimationTime(static_cast<GSuint>(m_modelID), static_cast<GSuint>(_animation)), _animationSpeed), _isLoop);
	/*物によっては切り替え時に初期化しない*/
	if (_isNotInit)
		return;
	m_currentAnimation->initialize();
}
const bool AnimatorOne::isEndCurrentAnimation() const
{
	return m_currentAnimation->getIsEnd();
}

bool AnimatorOne::isEndAnimation(ANIMATION_ID _animationID)
{
	return false;
}
