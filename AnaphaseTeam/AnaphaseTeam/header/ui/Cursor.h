#pragma once
#include <unordered_map>
#include "SelectUI.h"
class SelectCursor
{
public:
	SelectCursor();
	~SelectCursor();
	void initialize();
	void add(Select _key, const GSvector2& _position);
	void draw(const Renderer& _renderer, Select _select);
private:
	std::unordered_map<Select, GSvector2> m_filed;
};