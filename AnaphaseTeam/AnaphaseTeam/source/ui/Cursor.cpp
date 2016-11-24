#include  "../../header/ui/Cursor.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
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

void SelectCursor::draw(IRenderer * _renderer,Select _select)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::CURSOR);
	GStexture* tex = gsGetTexture(desc.textureID);
	desc.srcRect = GSrect(0, 0, tex->dwWidth, tex->dwHeight);
	desc.matrix.setTranslation(m_filed.at(_select));
	_renderer->render(desc);
}
