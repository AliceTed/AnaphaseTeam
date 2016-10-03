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
	///*���̃A�j���[�V�����Ɠ����Ȃ�ς��Ȃ�
	if (m_currentAnimation->getAnimationNo() == static_cast<unsigned int>(_animation) && _animationSpeed == m_currentAnimation->getSpeed())
		return;

	m_currentAnimation = std::make_shared<Animation>(m_modelID,cast(_animation), AnimationTimer(gsGetEndAnimationTime(cast(m_modelID),cast(_animation)), _animationSpeed), _isLoop);
	///*���ɂ���Ă͐؂�ւ����ɏ��������Ȃ�
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
	GSmatrix4 *orientedMat = new GSmatrix4[n];//�p���ϊ��s��z��
	GSmatrix4 *animMat = new GSmatrix4[n];//�A�j���[�V�����s��z��
	//�A�j���[�V�����̌v�Z
	gsCalculateAnimation(
		cast(m_modelID),
		m_currentAnimation->getAnimationNo(),
		m_currentAnimation->getcurrentTime(), animMat);
	//�X�P���g�����̌v�Z
	gsCalculateSkeleton(NULL, animMat, orientedMat);
	//�X�P���g���̈ʒu�����v�Z
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