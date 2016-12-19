#include "../../header/ui/Number.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"

#include <sstream>
#include <string>

Number::Number(TEXTURE_ID _id, const GSvector2 & _position)
	:m_id(_id),
	m_position(_position)
{
}

Number::~Number()
{
}

std::string Number::intToString(int _number)
{
	std::stringstream ss;
	ss << _number;
	return ss.str();
}


void Number::draw(IRenderer * _renderer,int _nunber)
{
	SpriteRectRenderDesc desc;
	for (auto& i : intToString(_nunber))
	{
		desc.srcRect = GSrect((i - '0') * 32, 0, 32, 64);
		//m_position.x += 32;
	}
	desc.color.a = 1.0;
	desc.matrix.translate(m_position);
	desc.textureID = static_cast<GSuint>(m_id);
	_renderer->render(desc);
	

}
