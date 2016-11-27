#include "..\..\..\header\data\stream\AttackConverter.h"
#include <algorithm>
#include <sstream>
#include "../../../header/attack/LoadAttack.h"
const bool AttackConverter::operator()(LoadAttack * _out, const std::string & _data) const
{
	std::string text = _data;
	std::replace(text.begin(), text.end(), ',', ' ');
	std::stringstream data(text);
	
	unsigned int itype;
	data >> itype;
	ATTACK_TYPE type= static_cast<ATTACK_TYPE>(itype);

	AttackStatus status;
	data >> status.m_power;
	data >> status.m_blowOff.x;
	data >> status.m_blowOff.y;
	data >> status.m_blowOff.z;

	unsigned int ianimation;
	data >> ianimation;
	ANIMATION_ID animation = static_cast<ANIMATION_ID>(ianimation);

	unsigned int iquick;
	data >> iquick;
	ATTACK_TYPE quick= static_cast<ATTACK_TYPE>(iquick);

	unsigned int islow;
	data >> islow;
	ATTACK_TYPE slow = static_cast<ATTACK_TYPE>(islow);

	if (data.fail())
	{
		return false;
	}
	_out->m_type = type;
	_out->m_attack = Attack(status, animation, quick, slow);	
	return true;
}
