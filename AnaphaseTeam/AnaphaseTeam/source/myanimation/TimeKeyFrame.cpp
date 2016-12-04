#include "../../header/myanimation/TimeKeyFrame.h"

TimeKeyFrame::TimeKeyFrame()
	:target(), time(0)
{
}

TimeKeyFrame::TimeKeyFrame(const Transform & _target, float _time)
	:target(_target),time(_time)
{
}
