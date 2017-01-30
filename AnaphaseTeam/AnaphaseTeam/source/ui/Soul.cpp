#include "../../header/ui/Soul.h"
#include "../header/renderer/define/SpriteRenderDesc.h"

Soul::Soul(const GSvector2 & _position, const GSvector2 & _target,int _lerpTime)
	:m_lerp(_position)
{
	m_lerp.start(_position, _target, _lerpTime);
}

void Soul::update(float _deltaTime)
{	
	m_lerp.update(_deltaTime);
}

void Soul::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.matrix.translate(m_lerp.current());
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::EXIT);
	desc.color.a = LERP(m_lerp.getRate(), 0, 1);
	_renderer->render(desc);
}

bool Soul::isDead() const
{
	return m_lerp.isEnd();
}
