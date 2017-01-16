#pragma once
#include "IEnemyAI.h"
#include <unordered_map>
#include <memory>
#include "EAI.h"
typedef std::shared_ptr<IEnemyAI> AI_Ptr;


class EnemyAIController
{
public:
	EnemyAIController();
	~EnemyAIController();
	void initialize();
	void think(Player* _player);
	void add(EAI _key,AI_Ptr _ai);
	void change(EAI _key);
	EAI currentRange();
private:
	std::unordered_map<EAI, AI_Ptr> m_aicontainer;
	EAI m_currentKey;
};
