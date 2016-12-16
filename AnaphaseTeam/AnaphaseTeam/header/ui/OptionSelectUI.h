#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class OPTION
{
	CONFIG,
	SOUND,
	TITLE,

	RESET = 99

};

typedef std::pair<const OPTION, ScaleImage> SelectOption;

class OptionSelectUI
{
public:
	OptionSelectUI();
	~OptionSelectUI();
	void initialize();
	void add(OPTION _name, const ScaleImage& _image);
	void next
		();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);

	void previous();
	const OPTION current()const;
	void startChange();
private:
	void change(OPTION _next);

private:
	std::unordered_map<OPTION, ScaleImage> m_images;
	OPTION m_option;

	const static GSvector2 DEFAULTSCALE;
	const static GSvector2 SELECTSCALE;
	const static float LERPTIME;

};
