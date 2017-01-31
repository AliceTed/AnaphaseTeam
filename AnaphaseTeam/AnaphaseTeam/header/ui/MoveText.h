#pragma once
#include "math/TimeLerpVector.h"
#include "renderer/IRenderer.h"
#include <string>
class MoveText
{
public:
	MoveText(const std::string & _text, const GSvector2 & _start, const GSvector2 & _end,int _size);
	~MoveText() = default;
	void update(float _deltTime);
	void draw(IRenderer * _renderer);
	bool isEnd()const;
private:
	std::string m_text;
	Math::TimeLerpVector<GSvector2> m_lerp;
	int m_size;
};
