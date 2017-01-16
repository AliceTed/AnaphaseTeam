#include "..\..\..\header\data\stream\AttackConverter.h"
#include <algorithm>
#include <sstream>
#include "attack/LoadAttack.h"
#include "shape/Sphere.h"
#include "shape/Capsule.h"
#include "data/json/JObject.h"
#include "data/json/JArray.h"
const bool AttackConverter::operator()(LoadAttack * _out, picojson::value& _value) const
{
	JUtil::JObject obj(_value.get<picojson::object>());
	if (!obj.isPossess("SelfID"))return false;
	_out->selfID =obj.get<std::string>("SelfID");

	if (!obj.isPossess("Aniamtion"))return false;	
	_out->parameter.animationID = obj.getNumber<unsigned int>("Aniamtion");

	if (!obj.isPossess("AniamtionSpeed"))return false;
	_out->parameter.speed = obj.getNumber<float>("AniamtionSpeed");

	if (!obj.isPossess("InputTime"))return false;
	_out->parameter.nextInput = obj.getNumber<float>("InputTime");
	
	if (!obj.isPossess("Power"))return false;
	_out->parameter.status.m_power = obj.getNumber<float>("Power");

	if (!obj.isPossess("BlowOff"))return false;
	JUtil::JArray blowoff(obj.get<picojson::array>("BlowOff"));
	_out->parameter.status.m_blowOff = blowoff.toVec3();

	if (!obj.isPossess("SlowID"))return false;
	_out->parameter.slowID = obj.get<std::string>("SlowID");

	if (!obj.isPossess("QucikID"))return false;
	_out->parameter.quickID = obj.get<std::string>("QucikID");

	if (!obj.isPossess("SpawnTime"))return false;
	_out->parameter.shapeData.spawnTime = obj.getNumber<float>("SpawnTime");
	if (!obj.isPossess("DestroyTime"))return false;
	_out->parameter.shapeData.destroyTime= obj.getNumber<float>("DestroyTime");
	if (!obj.isPossess("ShapeType"))return false;
	SHAPE_TYPE type= static_cast<SHAPE_TYPE>(obj.getNumber<unsigned int>("ShapeType"));
	_out->parameter.shapeData.type = type;
	if (!obj.isPossess("ShapeData"))return false;
	JUtil::JObject shapeObj(obj.get<picojson::object>("ShapeData"));
	return selectConvert(&_out->parameter.shapeData, shapeObj, type);
}

const bool AttackConverter::selectConvert(ShapeData* _out, JUtil::JObject & _obj, SHAPE_TYPE _type) const
{
	if (SHAPE_TYPE::SPHERE == _type)
	{
		return sphereConvert(_out,_obj);
	}
	return capsuleConvert(_out, _obj);
}

const bool AttackConverter::capsuleConvert(ShapeData* _out, JUtil::JObject & _obj) const
{
	if (!_obj.isPossess("ShapePosition"))return false;
	JUtil::JArray p_array(_obj.get<picojson::array>("ShapePosition"));
	GSvector3 pos = p_array.toVec3();
	if (!_obj.isPossess("ShapeRadius"))return false;
	float radius = _obj.getNumber<float>("ShapeRadius");

	if (!_obj.isPossess("CapsuleDirection"))return false;
	JUtil::JArray dir_array(_obj.get<picojson::array>("CapsuleDirection"));
	GSvector3 dir = dir_array.toVec3();
	dir.normalize();
	if (!_obj.isPossess("CapsuleHight"))return false;
	float hight=_obj.getNumber<float>("CapsuleHight");
	
	_out->shape = std::shared_ptr<Shape>(new Capsule(GSvector3(0,0,0),dir, hight, radius));
	_out->offset = pos;
	return true;
}

const bool AttackConverter::sphereConvert(ShapeData* _out, JUtil::JObject & _obj) const
{
	if (!_obj.isPossess("ShapePosition"))return false;
	JUtil::JArray p_array(_obj.get<picojson::array>("ShapePosition"));
	GSvector3 pos = p_array.toVec3();
	if (!_obj.isPossess("ShapeRadius"))return false;
	float radius=_obj.getNumber<float>("ShapeRadius");
	_out->shape= std::make_shared<Sphere>(GSvector3(0, 0, 0),radius);
	_out->offset = pos;
	return true;
}
