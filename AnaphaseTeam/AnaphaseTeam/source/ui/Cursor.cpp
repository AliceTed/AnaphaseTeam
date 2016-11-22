#include  "../../header/ui/Cursor.h"
#include "../../header/renderer/Renderer.h"
SelectCursor::SelectCursor()
	:m_filed()
{
}

SelectCursor::~SelectCursor()
{
}

void SelectCursor::initialize()
{
	m_filed.clear();
}

void SelectCursor::add(Select _key, const GSvector2 & _position)
{
	m_filed.insert(std::make_pair(_key, _position));
}

void SelectCursor::draw(const Renderer & _renderer,Select _select)
{
	_renderer.getDraw2D().textrue(TEXTURE_ID::CURSOR, &m_filed.at(_select));
}
