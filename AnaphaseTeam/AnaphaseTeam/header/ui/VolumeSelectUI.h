#pragma once
#pragma once
#include "ScaleImage.h"
#include <unordered_map>

enum class VOLUME
{
	HIGH,
	NORMAL,
	LOW,

	RESET = 99

};

typedef std::pair<const VOLUME, ScaleImage> SelectVolime;

class VolumeSelectUI
{
public:
	VolumeSelectUI();
	~VolumeSelectUI();
	void initialize();
	void add(VOLUME _name, const ScaleImage& _image);
	void next();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);

	void previous();
	const VOLUME current()const;
	void startChange();
private:
	void change(VOLUME _next);

private:
	std::unordered_map<VOLUME, ScaleImage> m_images;
	VOLUME m_volume;

	const static GSvector2 DEFAULTSCALE;
	const static GSvector2 SELECTSCALE;
	const static float LERPTIME;

};
