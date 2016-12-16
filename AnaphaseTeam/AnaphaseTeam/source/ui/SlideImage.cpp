#include "../../header/ui/SlideImage.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
SlideImage::SlideImage(TEXTURE_ID _id, const GSvector2 & _begin, const GSvector2 & _end)
	:m_begin(_begin),
	m_end(_end),
	m_id(_id),
	m_lerp(_begin),
	m_scale(1.0f,1.0f)
{
}

SlideImage::~SlideImage()
{
}

void SlideImage::slide(float _time, MODE _mode)
{
	if (_mode == MODE::REVERSE)
	{
		m_lerp.start(m_end, m_begin, _time);
		return;
	}
	m_lerp.start(m_begin,m_end,_time);
}

void SlideImage::update(float deltaTime)
{
	m_lerp.update(deltaTime);
}

void SlideImage::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_id);
	desc.matrix.setTranslation(m_lerp.current());
	desc.matrix.scale(m_scale);
	_renderer->render(desc);
}

void SlideImage::scaleChange()
{
	m_scale = GSvector2(1.1, 1.1);
}

void SlideImage::reset()
{
	m_scale = GSvector2(1.0, 1.0);
}
