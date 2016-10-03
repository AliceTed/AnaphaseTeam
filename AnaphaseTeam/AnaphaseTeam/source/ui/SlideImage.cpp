#include "../../header/ui/SlideImage.h"
#include "../../header/renderer/Renderer.h"
SlideImage::SlideImage(TEXTURE_ID _id, const GSvector2 & _begin, const GSvector2 & _end)
	:m_begin(_begin),
	m_end(_end),
	m_id(_id),
	m_lerp(_begin)
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

void SlideImage::draw(const Renderer & _renderer)
{
	_renderer.getDraw2D().textrue(m_id,&m_lerp.current());
}
