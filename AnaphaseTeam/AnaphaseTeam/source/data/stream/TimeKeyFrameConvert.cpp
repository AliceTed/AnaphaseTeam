#include "..\..\..\header\data\stream\TimeKeyFrameConvert.h"
#include <algorithm>
#include <sstream>
#include "../../../header/myanimation/TimeKeyFrame.h"
const bool TimeKeyFrameConvert::operator()(TimeKeyFrame * _out, const std::string & _data) const
{
	std::string text = _data;
	std::replace(text.begin(), text.end(), ',', ' ');
	std::stringstream data(text);

	GSvector3 translate;
	data >> translate.x;
	data >> translate.y;
	data >> translate.z;

	float angle;
	data >> angle;

	GSvector3 axis;
	data >> axis.x;
	data >> axis.y;
	data >> axis.z;
	axis.normalize();

	GSvector3 scale;
	data >> scale.x;
	data >> scale.y;
	data >> scale.z;

	float time;
	data >> time;

	if (data.fail())
	{
		return false;
	}
	_out->target = Transform(angle,axis,translate,scale);
	_out->time = time;
	return true;
}
