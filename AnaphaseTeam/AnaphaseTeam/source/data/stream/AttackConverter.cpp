#include "..\..\..\header\data\stream\AttackConverter.h"
#include <algorithm>
#include <sstream>
#include "../../../header/attack/LoadAttack.h"
#include "../../../header/shape/Sphere.h"
#include "../../../header/shape/Capsule.h"
const bool AttackConverter::operator()(LoadAttack * _out, const std::string & _data) const
{
	std::string text = _data;
	std::replace(text.begin(), text.end(), ',', ' ');
	std::stringstream data(text);
	
	std::string self;
	data >> self;

	float power;
	data >> power;
	GSvector3 blowoff;
	data >> blowoff.x;
	data >> blowoff.y;
	data >> blowoff.z;
	unsigned int animationID;
	data >> animationID;

	float speed;
	data >> speed;
	float nextInput;
	data >> nextInput;

	std::string slowID;
	data >> slowID;
	std::string quickID;
	data >> quickID;

	float spawnTime;
	data >> spawnTime;
	float destroyTime;
	data >> destroyTime;

	int itype;
	data >> itype;
	SHAPE_TYPE shapeType = static_cast<SHAPE_TYPE>(itype);

	GSvector3 offset;
	data >>offset.x;
	data >>offset.y;
	data >>offset.z;

	float radius;
	data >> radius;
	GSvector3 pos(0.0f, 0.0f, 0.0f);
	std::shared_ptr<Shape> shape;
	if (SHAPE_TYPE::SPHERE == shapeType)
	{
		shape = std::make_shared<Sphere>(pos, radius);
	}
	else
	{
		GSvector3 dir;
		data >> dir.x;
		data >> dir.y;
		data >> dir.z;
		dir.normalize();
		float hight;
		data >> hight;

		dir *= hight;
		Segment seg(pos, dir);
		shape = std::make_shared<Capsule>(seg, radius);
	}
	if (data.fail())
	{
		return false;
	}
	_out->selfID = self;
	_out->parameter.animationID = animationID;
	_out->parameter.speed = speed;
	_out->parameter.nextInput = nextInput;
	_out->parameter.quickID = quickID;
	_out->parameter.slowID = slowID;
	_out->parameter.status.m_blowOff = blowoff;
	_out->parameter.status.m_power = power;
	_out->parameter.shapeData.destroyTime = destroyTime;
	_out->parameter.shapeData.spawnTime = spawnTime;
	_out->parameter.shapeData.type = shapeType;
	_out->parameter.shapeData.offset = offset;
	_out->parameter.shapeData.shape = shape;
	return true;
}
