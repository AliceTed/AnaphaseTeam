#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class Select
{
	GAMESTART,
	OPTION,
	STAFFROLL,
	EXIT
};
typedef std::pair<const Select,ScaleImage> SelectValue;
class SelectUI
{
public:
	SelectUI();
	~SelectUI();
	void initialize();
	void add(Select _name,const ScaleImage& _image);
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
	
	void next();
	void previous();
	const Select currentSelect()const;
	void startChange();
	void startMove();
	bool isStart();
private:
	void change(Select _next);
private:
	Select m_current;
	std::unordered_map<Select, ScaleImage> m_images;
	float m_timer;
	GSvector2 m_end;

	const static GSvector2 DEFAULTSCALE;
	const static GSvector2 SELECTSCALE;
	const static GSvector2 DECISIONSCALE;
	const static float LERPTIME;
};
