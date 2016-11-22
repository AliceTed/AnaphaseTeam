#include "../../header/ui/ScaleImage.h"
#include "../../header/renderer/Renderer.h"
ScaleImage::ScaleImage(TEXTURE_ID _id, const GSvector2& _position, bool _isPexis)
	:m_id(_id), m_position(_position),
	m_lerp(GSvector2(1.0f, 1.0f)),
	m_isPexis(_isPexis)
{
}

ScaleImage::~ScaleImage()
{
}

void ScaleImage::start(const GSvector2 & _start, const GSvector2 & _end, float _time)
{
	m_lerp.start(_start, _end, _time);
}
void ScaleImage::update(float deltaTime)
{
	m_lerp.update(deltaTime);
}

void ScaleImage::draw(const Renderer & _renderer)
{
	GSvector2 scale = m_lerp.current();
	GSvector2 pos = m_position;
	if (!m_isPexis)
	{
		pos -= getSizeMarge(scale)*0.5f;
	}
	_renderer.getDraw2D().textrue(m_id, &pos, &scale);
}
const GSvector2 ScaleImage::getTextureSize() const
{
	GStexture* tex = gsGetTexture(static_cast<GSuint>(m_id));
	return GSvector2(tex->dwWidth, tex->dwHeight);
}

const GSvector2 ScaleImage::getSizeMarge(const GSvector2 & _scale) const
{
	GSvector2 size(getTextureSize());
	GSvector2 endSize = size*_scale;
	return endSize - size;
}
