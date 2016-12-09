#pragma once
#include "IEnemyAI.h"
#include <unordered_map>
#include <memory>
typedef std::shared_ptr<IEnemyAI> AI_Ptr;
enum class EAI
{
	OVERNEAR,
	ATTACKRANGE
};

class EnemyAIController
{
public:
	EnemyAIController();
	~EnemyAIController();
	void initialize();
	void think(Player* _player);
	void add(EAI _key,AI_Ptr _ai);
	void change(EAI _key);
private:
	std::unordered_map<EAI, AI_Ptr> m_aicontainer;
	EAI m_currentKey;
};
