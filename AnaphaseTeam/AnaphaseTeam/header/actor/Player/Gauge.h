#pragma once
#include "../../../header/renderer/Renderer.h"
#include <vector>

enum class RankGauge
{
	ZERO = 0,
	FIRST = 150,
	SECOND = 250,
	THIRD = 600,
	MAX = 1000
};

class Gauge
{
public:
	Gauge();
	~Gauge();
	void initialize();
	void draw(const Renderer& _renderer);
	void up(float _scale);
	bool down(float _scale);
	void downGauge(RankGauge _rankGauge);

	float scale(float def);
private:
	void add(float _point);
	void lerp(float* out, const float* min, const float* max, float time);
private:
	float m_gauge;
};