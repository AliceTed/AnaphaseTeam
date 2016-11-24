#include "../../header/attack/ComboReader.h"
#include "../../header/attack/AttackPattern.h"
#include "../../header/attack/ECombo.h"
#include "../../header/attack/AttackStatus.h"
#include "../../header/attack/Attack.h"
#include "../../header/data/ANIMATION_ID.h"
#include "../../header/actor/Player/Player.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

ComboReader::ComboReader()
	:m_current(0)
	,m_StatusOut()
	,m_Nowcombo()
{	
}

ComboReader::~ComboReader()
{}

bool ComboReader::ComboCreate(std::vector<Attack>* _attackOut, std::unordered_map<Combo, Attack>* _comboPattern)
{
	_comboPattern->clear();
	std::ifstream ifs("./res/Combo.txt");
	std::vector<std::string> sdata;
	sdata.clear();
	std::string line;
	int count;
	count = 0;
	while (getline(ifs, line))
	{
		sdata.emplace_back(line);
		m_current = count++;
	}

	for (auto& i : sdata)
	{
		std::replace(i.begin(), i.end(), ',', ' ');
		std::stringstream data(i);

		float attackPower;
		data >> attackPower;

		float distanceDecay;
		data >> distanceDecay;

		GSvector3 blowOffPower;
		data >> blowOffPower.x;
		data >> blowOffPower.y;
		data >> blowOffPower.z;

		AttackStatus status(attackPower, distanceDecay, GSvector3(blowOffPower.x, blowOffPower.y, blowOffPower.z));
		m_StatusOut.emplace_back(AttackStatus(attackPower, distanceDecay, GSvector3(blowOffPower.x, blowOffPower.y, blowOffPower.z)));

		Combo nowCombo;
		unsigned int now_c;
		data >> now_c;
		nowCombo = static_cast<Combo>(now_c);
		m_Nowcombo.emplace_back(nowCombo);

		ANIMATION_ID animation_id;
		unsigned int id;
		data >> id;
		animation_id = static_cast<ANIMATION_ID>(id);

		Combo Qcombo;
		unsigned int Q;
		data >> Q;
		Qcombo = static_cast<Combo>(Q);

		Combo Scombo;
		unsigned int S;
		data >> S;
		Scombo = static_cast<Combo>(S);

		_attackOut->emplace_back(Attack(status, animation_id, Qcombo, Scombo));

	}
	for (int i = 0; i < m_current; i++)
	{
		_comboPattern->insert(std::make_pair(m_Nowcombo.at(i), _attackOut->at(i)));
	}

	return true;
}


