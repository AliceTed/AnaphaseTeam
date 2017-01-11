#pragma once
#include "Picojson.h"
#include <GSvector3.h>
namespace JUtil
{
	class JArray
	{
	public:
		JArray(const picojson::array& _array);
		~JArray() = default;
		const bool isEmpty()const;
		const unsigned int size()const;
		const GSvector2 toVec2();
		const GSvector3 toVec3();
		const picojson::value& at(unsigned int _index)const;
		picojson::value& operator[](unsigned int _index);

		double getDouble(unsigned int _index);
		template<class T>
		T getNumber(unsigned int _index);
		template<class T>
		T get(unsigned int _index);
	private:
		picojson::array m_array;
	};
}
//template<>
//double JUtil::JArray::getNumber(unsigned int _index)
//{
//	return m_array.at(_index).get<double>();
//}
template<class T>
T JUtil::JArray::getNumber(unsigned int _index)
{
	return static_cast<T>(getDouble(_index));
}

template<class T>
T JUtil::JArray::get(unsigned int _index)
{
	return m_array.at(_index).get<T>();
}