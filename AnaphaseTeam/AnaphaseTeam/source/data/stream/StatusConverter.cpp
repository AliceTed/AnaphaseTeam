#include "../../../header/data/stream/StatusConverter.h"
#include "../../../header/actor/Player/LoadStatus.h"
#include "../../../header/shape/Capsule.h"
#include "../../../header/data/json/JObject.h"
#include "../../../header/data/json/JArray.h"

const bool StatusConverter::operator()(LoadStatus * _out, picojson::value & _value) const
{
	JUtil::JObject obj(_value.get<picojson::object>());
	if (!obj.isPossess("SelfID"))return false;
	_out->selfID = obj.get<std::string>("SelfID");
	
	if (!obj.isPossess("HP")) return false;
	_out->parameter.m_hp = obj.getNumber<float>("HP");

	//if (!obj.isPossess("ShapeData"))return false;
	//JUtil::JObject shapeObj(obj.get<picojson::object>("ShapeData"));
	
	//return selectConvert(_out->parameter.shapeData.shape, shapeObj);
	return true;
}

const bool StatusConverter::selectConvert(shared_ptr<Shape>& _out, JUtil::JObject & _obj) const
{
	return capsuleConvert(_out, _obj);
}

const bool StatusConverter::capsuleConvert(shared_ptr<Shape>& _out, JUtil::JObject & _obj) const
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
	float hight = _obj.getNumber<float>("CapsuleHight");

	//_out = make_shared<Shape>(Capsule(pos, dir, hight, radius));
	return true;
}
