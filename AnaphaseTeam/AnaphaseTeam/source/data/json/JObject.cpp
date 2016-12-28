#include "..\..\..\header\data\json\JObject.h"

JUtil::JObject::JObject(const picojson::object & _object)
	:m_object(_object) {}

const bool JUtil::JObject::isPossess(const std::string & _key) const
{
	return m_object.count(_key) != 0;
}

double JUtil::JObject::getDouble(const std::string & _key)
{
	return m_object.at(_key).get<double>();
}

const picojson::value & JUtil::JObject::at(const std::string & _key) const
{
	return m_object.at(_key);
}

picojson::value & JUtil::JObject::operator[](const std::string & _key)
{
	return m_object[_key];
}
