#include "../../header/animation/AnimatorOne.h"
#include "../../header/data/CastID.h"
#include <gslib.h>
AnimatorOne::AnimatorOne(const MODEL_ID _modelID) :
	m_modelID(_modelID), m_currentAnimation(nullptr),
	m_nextAnimation(nullptr), m_matPtr(std::unique_ptr<GSmatrix4>(new GSmatrix4[256]))
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
/*void AnimatorOne::changeAnimation(ANIMATION_ID _animation, bool _isLoop, bool _isNotInit, float _animationSpeed)
{
	Data::CastID cast;
	if (m_currentAnimation == nullptr)
		m_currentAnimation = std::make_shared<Animation>(m_modelID,cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID),cast(_animation)), _animationSpeed), _isLoop);
	///*今のアニメーションと同じなら変えない
	if (m_currentAnimation->getAnimationNo() == static_cast<unsigned int>(_animation) && _animationSpeed == m_currentAnimation->getSpeed())
		return;

	m_currentAnimation = std::make_shared<Animation>(m_modelID,cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID),cast(_animation)), _animationSpeed), _isLoop);
	///*物によっては切り替え時に初期化しない
	if (_isNotInit)
		return;
	m_currentAnimation->initialize();
}*/
const bool AnimatorOne::isEndCurrentAnimation() const
{
	return m_currentAnimation->getIsEnd();
}

bool AnimatorOne::isEndAnimation(ANIMATION_ID _animationID)
{
	return false;
}

void AnimatorOne::changeAnimation(ANIMATION_ID _animation,bool _isLerp ,bool _isLoop, bool _isNotInit, float _animationSpeed)
{
	Data::CastID cast;
	if (m_currentAnimation == nullptr)
		m_currentAnimation = std::make_shared<Animation>(m_modelID, cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID), cast(_animation)), _animationSpeed), _isLoop);
	///*今のアニメーションと同じなら変えない
	if (m_currentAnimation->getAnimationNo() == static_cast<unsigned int>(_animation) && _animationSpeed == m_currentAnimation->getSpeed())
		return;
	if (_isLerp)
	{
		lerpBegin(_animation, !_isNotInit, _isLoop);
		return;
	}
	m_currentAnimation = std::make_shared<Animation>(m_modelID, cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID), cast(_animation)), _animationSpeed), _isLoop);
	///*物によっては切り替え時に初期化しない
	if (_isNotInit)
		return;
	m_currentAnimation->initialize();
}


void AnimatorOne::change(Animation_Ptr _next)
{
	m_currentAnimation = m_nextAnimation;
	if (m_lerpData.m_nextInit)
	{
		m_currentAnimation->initialize();
	}
}
void AnimatorOne::lerpBegin(ANIMATION_ID _anim, bool _init, bool _loop,float _animSpeed)
{
	m_lerpData.m_startTime = m_currentAnimation->getCurrentTime();
	m_lerpData.m_endTime = 0;
	m_lerpData.m_nextInit = _init;
	m_nextAnimation = std::make_shared<Animation>(m_modelID, static_cast<unsigned int>(_anim), AnimationTimer(gsGetEndAnimationTime(static_cast<unsigned int>(m_modelID), static_cast<unsigned int>(_anim)), _animSpeed), _loop);
}

void AnimatorOne::animationCaluculate(GSmatrix4* _animMat)
{
	Data::CastID cast;

	//nextが無ければ普通のアニメーション
	if (!m_nextAnimation)
	{
		gsCalculateAnimation(
			cast(m_modelID),
			m_currentAnimation->getAnimationNo(),
			m_currentAnimation->getCurrentTime(), _animMat);
		return;
	}
	//今と次が同じだとふつうのアニメーション
	if (m_nextAnimation->getAnimationNo() == m_currentAnimation->getAnimationNo())
	{
		gsCalculateAnimation(
			cast(m_modelID),
			m_currentAnimation->getAnimationNo(),
			m_currentAnimation->getCurrentTime(), _animMat);
		return;
	}
	//ラープする
	animationCaluculateLerp(_animMat);
}

void AnimatorOne::animationCaluculateLerp(GSmatrix4* _animMat)
{
	Data::CastID cast;
	
	gsCalculateAnimationLerp(cast(m_modelID), m_currentAnimation->getAnimationNo(), m_lerpData.m_startTime,
		cast(m_modelID), m_nextAnimation->getAnimationNo(), m_lerpData.m_endTime, m_lerpData.m_time / m_lerpData.m_lerpTime, _animMat);
	m_lerpData.timerUpdate();
	if (m_lerpData.lerpEnd())
	{
		change(m_nextAnimation);
		m_lerpData.timerInit();
	}
}

GSmatrix4* AnimatorOne::matrixCalculate()
{
	Data::CastID cast;
	gsBindSkeleton(cast(m_modelID));

	const GSuint n = getNumBones();
	std::unique_ptr<GSmatrix4> orientedMat = std::unique_ptr<GSmatrix4>(new GSmatrix4[256]);//姿勢変換行列配列
	std::unique_ptr<GSmatrix4> animMat = std::unique_ptr<GSmatrix4>(new GSmatrix4[256]);

	animationCaluculate(animMat.get());
	/*スケルトン情報の計算
	アニメーション行列をもとに姿勢変換行列を計算
	*/
	gsCalculateSkeleton(NULL, animMat.get(), orientedMat.get());
	/*スケルトンの位置情報を計算
	姿勢から座標へ
	*/
	gsSkeletonCalculateTransform(
		gsGetSkeleton(cast(m_modelID)),
		m_matPtr.get(),
		orientedMat.get());

	return m_matPtr.get();
}
const GSuint AnimatorOne::getNumBones()const
{
	return gsGetSkeletonNumBones(static_cast<GSuint>(m_modelID));
}

const GSmatrix4* AnimatorOne::getMat()const
{
	return m_matPtr.get();
}

const float AnimatorOne::getCurrentAnimationTime() const
{
	return m_currentAnimation->getCurrentTime();
}

const float AnimatorOne::getCurrentAnimationEndTime() const
{
	return m_currentAnimation->getEndTime();
}
