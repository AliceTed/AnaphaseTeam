#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class SOUND
{
	BGM,
	SE,

	RESET = 99

};

typedef std::pair<const SOUND, ScaleImage> SelectSound;

class SoundSelectUI
{
public:
	SoundSelectUI();
	~SoundSelectUI();
	void initialize();
	void add(SOUND _name, const ScaleImage& _image);
	void next();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);

	void previous();
	const SOUND current()const;
	void startChange();
private:
	void change(SOUND _next);

private:
	std::unordered_map<SOUND, ScaleImage> m_images;
	SOUND m_sound;
	const static GSvector2 DEFAULTSCALE;
	const static GSvector2 SELECTSCALE;
	const static float LERPTIME;

};
