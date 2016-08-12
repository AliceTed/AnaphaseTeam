#include "../../header/animation/Animation.h"
#include <gslib.h>


Animation::Animation(ANIMATION_ID anim_id, SKELETON_ID bone_id, unsigned int animNo,AnimationTimer timer, bool isLoop)
	:isLoop(isLoop), animNo(animNo), timer(timer),
	anim_id(static_cast<unsigned int>(anim_id)), bone_id(static_cast<unsigned int>(bone_id))
{

}

Animation::~Animation()
{

}

void Animation::initialize()
{
	timer.initialize();
}

void Animation::update(float deltaTime)
{
	timer.update(deltaTime);
	looping();
}
void Animation::bind()
{
	gsBindAnimation(anim_id, animNo, timer.getTime());
	gsBindSkeleton(bone_id);
}

const bool Animation::getIsEnd() const
{
	return (!isLoop)&&timer.getIsEnd();
}

void Animation::stop()
{
	timer.stop();
}

void Animation::start()
{
	timer.start();
}

void Animation::looping()
{
	if (!timer.getIsEnd())
	{
		return;
	}
	if (!isLoop)
	{
		return;
	}
	timer.initialize();
}
