#include "../../header/animation/AnimatorOne.h"
#include "../../header/data/id/CastID.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SkinnedMeshRenderDesc.h"
#include "../../header/data/id/SHADER_ID.h"
#include <gslib.h>
AnimatorOne::AnimatorOne(const MODEL_ID _modelID) :
	m_modelID(_modelID), m_currentAnimation(nullptr),
	m_nextAnimation(nullptr)//, m_matPtr(std::shared_ptr<GSmatrix4>(new GSmatrix4[256], std::default_delete<GSmatrix4[]>()))
	, m_orientedMat(std::shared_ptr<GSmatrix4>(new GSmatrix4[256], std::default_delete<GSmatrix4[]>()))
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
	matrixCalculate();
}
const bool AnimatorOne::isEndCurrentAnimation() const
{
	return /*(!m_nextAnimation) &&*/m_currentAnimation->getIsEnd();
}
//
//bool AnimatorOne::isEndAnimation(unsigned int _animationID)
//{
//	return false;
//}

void AnimatorOne::changeAnimationLerp(unsigned int _animation)
{
	changeAnimation(_animation, true, false, false, 10.0f, 1.0f);
}
void AnimatorOne::changeAnimationLerp(unsigned int _animation, float _animSpeed)
{
	changeAnimation(_animation, true, false, false, 10.0f, _animSpeed);
}
void AnimatorOne::changeAnimation(unsigned int _animation, bool _isLerp, bool _isLoop, bool _isNotInit, float _lerpTime, float _animationSpeed)
{
	Data::CastID cast;
	if (!m_currentAnimation)
		m_currentAnimation = std::make_shared<Animation>(m_modelID, cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID), cast(_animation)), _animationSpeed), _isLoop);
	///*今のアニメーションと同じなら変えない
	if (m_currentAnimation->getAnimationNo() == cast(_animation) && _animationSpeed == m_currentAnimation->getSpeed())
		return;
	if (_isLerp)
	{
		lerpBegin(_animation, !_isNotInit, _isLoop, _lerpTime, _animationSpeed);
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
	m_nextAnimation = nullptr;
}
void AnimatorOne::lerpBegin(unsigned int _anim, bool _init, bool _loop, float _lerpTime, float _animSpeed)
{
	m_lerpData.m_startTime = m_currentAnimation->getCurrentTime();
	m_lerpData.m_endTime = 0;
	m_lerpData.m_nextInit = _init;
	m_lerpData.m_lerpTime = _lerpTime;
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
		cast(m_modelID), m_nextAnimation->getAnimationNo(), m_lerpData.m_endTime,
		m_lerpData.m_time / m_lerpData.m_lerpTime, _animMat);
	m_lerpData.timerUpdate();
	if (m_lerpData.lerpEnd())
	{
		change(m_nextAnimation);
		m_lerpData.timerInit();
	}
}

void AnimatorOne::matrixCalculate()
{
	//Data::CastID cast;
	std::unique_ptr<GSmatrix4> animMat = std::unique_ptr<GSmatrix4>(new GSmatrix4[256]);
	animationCaluculate(animMat.get());
	/*スケルトン情報の計算
	アニメーション行列をもとに姿勢変換行列を計算
	*/
	gsSkeletonCalculateOrientation(gsGetSkeleton(static_cast<GSuint>(m_modelID)), m_orientedMat.get(), NULL, animMat.get());
	//下のはbindを使用したときの計算なので上のOrientation付きのものに変更
	//gsCalculateSkeleton(NULL, animMat.get(), m_orientedMat.get());
}

void AnimatorOne::skeltonCalculateTransform(GSmatrix4* _mat)
{

	/*スケルトンの位置情報を計算
	姿勢から座標へ
	*/
	gsSkeletonCalculateTransform(
		gsGetSkeleton(static_cast<GSuint>(m_modelID)),
		//m_matPtr.get(),
		_mat,
		m_orientedMat.get());
}

void AnimatorOne::draw(IRenderer * _renderer,const Transform &_transform, const GScolor &_color)
{
	//matrixCalculate();
	std::unique_ptr<GSmatrix4>mat(new GSmatrix4[256]);
	skeltonCalculateTransform(mat.get());
	SkinnedMeshRenderDesc desc;
	desc.meshID = static_cast<GSuint>(m_modelID);
	desc.shaderID = static_cast<GSuint>(SHADER_ID::SKINNEDMESH);
	desc.matrix = _transform.matrix();
	desc.animation = mat.get();
	_renderer->render(desc);
}

//const GSuint AnimatorOne::getNumBones()const
//{
//	return gsGetSkeletonNumBones(static_cast<GSuint>(m_modelID));
//}

//const GSmatrix4& AnimatorOne::getMat(unsigned int index)const
//{
//	return m_matPtr.get()[index];
//}
const GSmatrix4& AnimatorOne::getOrientedMat(unsigned int index)const
{
	return m_orientedMat.get()[index];
}
const float AnimatorOne::getCurrentAnimationTime() const
{
	return m_currentAnimation->getCurrentTime();
}

const float AnimatorOne::getCurrentAnimationEndTime() const
{
	return m_currentAnimation->getEndTime();
}

const float AnimatorOne::getNextAnimationTime() const
{
	return m_nextAnimation->getCurrentTime();
}

const float AnimatorOne::getNextAnimationEndTime() const
{
	if (!m_nextAnimation)return 0.0f;
	return m_nextAnimation->getEndTime();
}
