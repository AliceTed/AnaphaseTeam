#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class Select
{
	GAMESTART,
	OPTION,
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
	void draw(const Renderer& _renderer);
	
	void next();
	void previous();
	const Select currentSelect()const;
	void startChange();
private:
	void change(Select _next);
private:
	Select m_current;
	std::unordered_map<Select, ScaleImage> m_images;

	const static GSvector2 MINSCALE;
	const static GSvector2 MAXSCALE;
	const static float LERPTIME;
};
