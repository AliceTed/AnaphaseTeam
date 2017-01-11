#pragma once
#include "Picojson.h"

namespace JUtil
{
	class JObject
	{
	public:
		JObject(const picojson::object& _object);
		~JObject()=default;
		//object�����L���Ă��邩�H
		const bool isPossess(const std::string& _key)const;
		double getDouble(const std::string& _key);
		template<class T>
		T getNumber(const std::string& _key);
		template<class T>
		T get(const std::string& _key);

		const picojson::value& at(const std::string &_key)const;
		picojson::value& operator[](const std::string &_key);
	private:
		picojson::object m_object;
	};
}
//���ꉻ�ł��Ȃ��@
//template<>
//double JUtil::JObject::getNumber(const std::string & _key)
//{
//	return m_object.at(_key).get<double>();
//}

template<class T>
T JUtil::JObject::getNumber(const std::string & _key)
{
	double value = getDouble(_key);
	return static_cast<T>(value);
}
template<class T>
T JUtil::JObject::get(const std::string & _key)
{
	return m_object.at(_key).get<T>();
}
