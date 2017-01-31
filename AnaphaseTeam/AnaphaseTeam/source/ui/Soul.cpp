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
	if (m_alpha <= 1)
	{
		m_alpha = LERP(m_lerp.getRate(), 0, 1);
	}
	if (m_alpha >= 1)
	{
		m_alpha = LERP(m_lerp.getRate(), 1, 0);
	}
}

void Soul::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.matrix.scale(LERP(m_lerp.getRate(), 1, 0), LERP(m_lerp.getRate(), 1, 0), 1);
	desc.matrix.translate(m_lerp.current());
	desc.blendFunc = BlendFunc::ADD;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::AURA);
	//desc.color.a = LERP(m_lerp.getRate(), 0, 1);
	desc.color.a = m_alpha;
	_renderer->render(desc);
}

bool Soul::isDead() const
{
	return m_lerp.isEnd();
}
