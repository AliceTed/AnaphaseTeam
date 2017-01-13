#pragma once

#include <memory>
#include "../json/Picojson.h"

struct LoadStatus;
class Shape;

namespace JUtil
{
	class JObject;
}

using namespace std;

class StatusConverter
{
public:
	const bool operator () (LoadStatus* _out, picojson::value& _value) const;

private:
	const bool selectConvert(shared_ptr<Shape>& _out, JUtil::JObject& _obj)const;
	const bool capsuleConvert(shared_ptr<Shape>& _out, JUtil::JObject& _obj)const;

};