#include "../../header/ui/ResultUI.h"
#include "../header/renderer/define/SpriteRenderDesc.h"

ResultUI::ResultUI(const GSvector2 & _position, const GSvector2 & _target, int _lerpTime)
	:m_lerp(_position),
	m_position(_position),
	m_target(_target),
	m_lerpTime(_lerpTime)

{
	
}

ResultUI::~ResultUI()
{
}

void ResultUI::Initilize()
{
	m_lerp.start(m_position, m_target, m_lerpTime);
}

void ResultUI::update(float _deltaTime)
{
	m_lerp.update(_deltaTime);
}

void ResultUI::draw(IRenderer * _renderer)
{
	/*SpriteRenderDesc desc;
	desc.matrix.translate(m_lerp.current());
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::GAMESTART);
	desc.color.a = LERP(m_lerp.getRate(), 0, 1);
	_renderer->render(desc);*/
}

bool ResultUI::isDead() const
{
	return m_lerp.isEnd();
}
