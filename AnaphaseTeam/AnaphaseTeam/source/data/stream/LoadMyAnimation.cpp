#include "../../../header/data/stream/LoadMyAnimation.h"
#include "../../../header/data/stream/DataReader.h"
#include "../../../header/data/stream/Convert.h"
#include "../../../header/myanimation/MyAnimation.h"
#include <fstream>
#include <sstream> 
#include <GSvector3.h>
#include "../../../header/myanimation/MyAnimationContainer.h"
const bool LoadMyAnimation::operator()(unsigned int _id, const std::string& _file, const std::string& _extension)const
{
	std::vector<std::string> s_data;
	s_data.clear();
	DataReader reader;
	if (!reader(&s_data, _file,_extension))
	{
		s_data.clear();
		return false;
	}
	std::vector<float> f_data;	
	Convert convert;
	MyAnimation* animation=new MyAnimation();
	animation->initialize();
	for each (auto line in s_data)
	{
		f_data.clear();
		if (!convert(&f_data, line))
		{
			f_data.clear();
			s_data.clear();
			return false;
		}
		if (!add(animation, f_data))
		{
			f_data.clear();
			s_data.clear();
			return false;
		}
	}
	MyAnimationContainer::getInstance().add(animation);
	f_data.clear();
	s_data.clear();
	return true;
}

const bool LoadMyAnimation::add(MyAnimation * _out, const std::vector<float>& _f_data) const
{
	//—v‘f”‚ª10(pos,rot,scale,time)‚¶‚á‚È‚¢ê‡
	if (!isJustCount(_f_data.size(), 10))return false;
	GSvector3 translate(_f_data[0], _f_data[1], _f_data[2]);
	GSvector3 rotate(_f_data[3], _f_data[4], _f_data[5]);
	GSvector3 scale(_f_data[6], _f_data[7], _f_data[8]);
	float time = _f_data[9];

    Transform t(rotate, translate, scale);
	_out->add(t, time);
	return true;
}

const bool LoadMyAnimation::isJustCount(unsigned int _size, unsigned int _target) const
{
	return _size==_target;
}