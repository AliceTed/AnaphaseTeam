#include "..\..\..\header\data\json\JArray.h"
#include <cassert>
JUtil::JArray::JArray(const picojson::array & _array)
	:m_array(_array)
{
}

const bool JUtil::JArray::isEmpty() const
{
	return m_array.empty();
}

const unsigned int JUtil::JArray::size() const
{
	return m_array.size();
}

const GSvector2 JUtil::JArray::toVec2() 
{
	const unsigned int LENGHT = 2;
	assert(size()>= LENGHT);
	GSvector2 res(0.0f, 0.0f);
	for (unsigned int i = 0; i < LENGHT; i++)
	{
		res.v[i] = getNumber<float>(i);
	}
	return res;
}

const GSvector3 JUtil::JArray::toVec3() 
{
	const unsigned int LENGHT = 3;
	assert(size() >= LENGHT);
	GSvector3 res(0.0f, 0.0f, 0.0f);
	for (unsigned int i = 0; i < LENGHT; i++)
	{
		res.v[i] = getNumber<float>(i);
	}
	return res;
}

const picojson::value & JUtil::JArray::at(unsigned int _index) const
{
	return m_array.at(_index);
}

picojson::value & JUtil::JArray::operator[](unsigned int _index)
{
	return m_array[_index];
}

double JUtil::JArray::getDouble(unsigned int _index)
{
	return m_array.at(_index).get<double>();
}


