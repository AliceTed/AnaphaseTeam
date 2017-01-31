#include "..\..\header\ui\Flash.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

Flash::Flash(TEXTURE_ID _ID, const GSvector2& _position, const Flash::Param& _param)
	:m_textureID(_ID),
	m_param(_param),
	m_position(_position),
	m_initparam(_param)
{

}

Flash::~Flash()
{
}

void Flash::initilize()
{
	m_param = m_initparam;
}

void Flash::update(float _deltaTime)
{
	float nextalpha = m_param.alpha + m_param.speed * _deltaTime * m_param.sign;
	m_param.alpha = CLAMP(nextalpha, 0, 1.0f);
	if (m_param.alpha >= 1.0f || m_param.alpha <= 0.0f)
	{
		m_param.sign *= -1;
	}
	
}

void Flash::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_textureID);
	desc.matrix.translate(m_position);
	desc.color.a = m_param.alpha;

	_renderer->render(desc);

}
