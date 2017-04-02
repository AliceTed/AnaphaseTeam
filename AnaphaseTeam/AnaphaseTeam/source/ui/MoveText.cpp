#include "ui/MoveText.h"
#include "renderer/define/StringRenderDesc.h"

MoveText::MoveText(const std::string & _text,const GSvector2 & _start,const GSvector2 & _end,int _size)
	:m_lerp(_start)
	,m_text(_text),
	m_size(_size)
{
	m_lerp.start(_start, _end, 5);
}

void MoveText::update(float _deltTime)
{
	m_lerp.update(_deltTime);
}

void MoveText::draw(IRenderer * _renderer)
{
	StringRenderDesc desc;
	Font font;
	font.size = m_size;
	desc.font = font;
	desc.string = m_text;
	desc.position = m_lerp.current();
	_renderer->render(desc);
}

bool MoveText::isEnd() const
{
	return m_lerp.isEnd();
}
