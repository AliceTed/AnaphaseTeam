#pragma once
#include "../data/id/TEXTURE_ID.h"
#include "../renderer/define/NumberSpriteRenderDesc.h"
#include <gslib.h>

class IRenderer;
class Number
{
public:
	Number(TEXTURE_ID _id);
	~Number();
	void initilize();
	void scroll();
	void update(float deltaTime);
	void flashing(float _addTime, float _decTime);
	void draw(IRenderer * _renderer, int _nunber);
	void reset();
private:
	TEXTURE_ID m_id;
	GSvector2 m_position;
	float m_alpha;
	bool m_alphaChange;

};