#pragma once
#include "../json/Picojson.h"
#include <memory>
#include "../../attack/SHAPE_TYPE.h"
struct LoadAttack;
struct ShapeData;
class Shape;
namespace JUtil
{
	class JObject;
}

class AttackConverter
{
public:
	const bool operator()(LoadAttack* _out, picojson::value& _value)const;

private:
	const bool selectConvert(ShapeData* _out, JUtil::JObject& _obj, SHAPE_TYPE _type)const;
	const bool capsuleConvert(ShapeData* _out, JUtil::JObject& _obj)const;
	const bool sphereConvert(ShapeData* _out, JUtil::JObject& _obj)const;
};
