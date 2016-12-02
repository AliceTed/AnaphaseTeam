#include "../../../header/data/stream/LoadMyAnimation.h"
#include "../../../header/data/stream/DataReader.h"
#include "../../../header/myanimation/MyAnimationContainer.h"
#include "../../../header/data/stream/TimeKeyFrameConvert.h"
const bool LoadMyAnimation::operator()(unsigned int _id, const std::string& _file, const std::string& _extension)const
{
	std::vector<std::string> data;
	data.clear();
	DataReader reader;
	if (!reader(&data, _file,_extension))
	{
		data.clear();
		return false;
	}
	MyAnimation* animation=new MyAnimation();
	animation->initialize();
	TimeKeyFrameConvert convert;
	for each (auto line in data)
	{
		TimeKeyFrame key;
		if (!convert(&key, line))
		{
			data.clear();
			return false;
		}
		animation->add(key);
	}
	MyAnimationContainer::getInstance().add(animation);
	data.clear();
	return true;
}