#pragma once
#include "../../../header/renderer/IRenderer.h"
#include "../../ui/IPlayUI.h"
#include <vector>

enum class RankGauge
{
	ZERO = 0,
	FIRST = 150,
	SECOND = 400,
	MAX = 1000
};

class Gauge:public IPlayUI
{
public:
	Gauge();
	~Gauge();
	void initialize();
	void draw(IRenderer * _renderer);
	void up(float _scale);
	bool down(float _scale);
	void downGauge(RankGauge _rankGauge);
	void update(float deltatime);

	float scale(float def);

	const bool isDown(float _value)const;
	float getGauge();
private:
	void add(float _point);

public:
	float m_gauge;
	float m_increaseGauge;

private:
	float m_lerpmax;
};