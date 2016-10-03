#include "../../header/animation/AnimatorOne.h"
#include "../../header/data/CastID.h"
#include <gslib.h>
AnimatorOne::AnimatorOne(const MODEL_ID _modelID) :
	m_modelID(_modelID), m_currentAnimation(nullptr), m_matrix(),m_mat()
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

void AnimatorOne::matrixCalculate(GSmatrix4* _reslut)
{
	Data::CastID cast;
	gsBindSkeleton(cast(m_modelID));

	const GSuint n = getNumBones();//gsGetSkeletonNumBones(static_cast<GSuint>(m_modelID));
	GSmatrix4 *orientedMat = new GSmatrix4[n];//姿勢変換行列配列
	GSmatrix4 *animMat = new GSmatrix4[n];//アニメーション行列配列
	//アニメーションの計算
	gsCalculateAnimation(
		cast(m_modelID),
		m_currentAnimation->getAnimationNo(),
		m_currentAnimation->getcurrentTime(), animMat);
	//スケルトン情報の計算
	gsCalculateSkeleton(NULL, animMat, orientedMat);
	//スケルトンの位置情報を計算
	gsSkeletonCalculateTransform(
		gsGetSkeleton(cast(m_modelID)),
		_reslut,
		orientedMat);
	m_mat = *_reslut;
	m_matrix.clear();
	m_matrix.emplace_back(*_reslut);
	delete[] orientedMat;
	delete[] animMat;
}

const GSuint AnimatorOne::getNumBones()const
{
	return gsGetSkeletonNumBones(static_cast<GSuint>(m_modelID));
}
const GSmatrix4 AnimatorOne::getMatrix()const
{
	return m_mat;
}