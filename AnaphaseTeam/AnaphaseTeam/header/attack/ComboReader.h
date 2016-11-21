#pragma once
#include <vector>
#include <unordered_map>


class AttackStatus;
class Attack;
class Player;
enum class Combo :unsigned int;

class ComboReader
{
public:
	ComboReader();
	~ComboReader();
	bool ComboCreate(std::vector<Attack>* _attackOut, std::unordered_map<Combo, Attack>* _comboPattern);
private:
	int m_current;
	std::vector<AttackStatus> m_StatusOut;
	std::vector<Combo> m_Nowcombo;

};
