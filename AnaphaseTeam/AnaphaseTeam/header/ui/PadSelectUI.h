#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class PAD
{
	PAD_A,
	PAD_B,
	RESET = 99
};

typedef std::pair<const PAD, ScaleImage> SelectPad;
class PadSelectUI
{
public:
	PadSelectUI();
	~PadSelectUI();
	void initialize();
	void add(PAD _name, const ScaleImage& _image);
	void next();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);

	void previous();
	const PAD current()const;
	void startChange();
private:
	void change(PAD _next);
private:
	std::unordered_map<PAD, ScaleImage> m_images;
	PAD m_pad;

	const static GSvector2 DEFAULTSCALE;
	const static GSvector2 SELECTSCALE;
	const static float LERPTIME;

};
