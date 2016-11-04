#pragma once
#include "../../../header/renderer/Renderer.h"
#include <vector>

enum RankGauge
{
	ZERO = 0,
	FIRST = 33,
	SECOND = 66,
	MAX = 100
};

class Gauge
{
public:
	Gauge();
	~Gauge();
	void initialize();
	void update();
	void draw(const Renderer& _renderer);
	void up(float _scale);
	bool down(float _scale);
	void downGauge(int _rank);

	float scale(float def);
private:
	void rankCheck();
	void add(float _point);
private:
	float m_gauge;
	RankGauge m_RankGauge;
	static const float MAXGAUGE;
	static const float MINGAUGE;
	static const float ONEGAUGE;
	
	std::vector<RankGauge> rankvector;
};