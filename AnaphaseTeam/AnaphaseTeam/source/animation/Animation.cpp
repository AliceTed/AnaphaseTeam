#include "../../header/animation/Animation.h"
#include <gslib.h>

Animation::~Animation()
{

}

void Animation::initialize()
{
	m_timer.initialize();
}

void Animation::update(float deltaTime)
{
	m_timer.update(deltaTime);
	looping();
}
//Žg‚Á‚Ä‚È‚¢
void Animation::bind()const
{
	gsBindAnimation(m_anim_id, m_animNo, m_timer.getTime());
	//gsBindSkeleton(m_bone_id);
}

const bool Animation::getIsEnd() const
{
	return (!m_isLoop) && m_timer.getIsEnd();
}

void Animation::stop()
{
	m_timer.stop();
}

void Animation::start()
{
	m_timer.start();
}

void Animation::looping()
{
	if (!m_timer.getIsEnd())
	{
		return;
	}
	if (!m_isLoop)
	{
		return;
	}
	m_timer.initialize();
}

unsigned int Animation::getAnimationNo()
{
	return m_animNo;
}
const float Animation::getSpeed()const
{
	return m_timer.getSpeed();
}

const float Animation::getEndTime() const
{
	return m_timer.getEndTime();
}

const float Animation::getCurrentTime() const
{
	return m_timer.getTime();
}

const bool Animation::getIsLoop()const
{
	return m_isLoop;
}