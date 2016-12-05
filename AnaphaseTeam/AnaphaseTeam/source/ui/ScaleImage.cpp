#include "../../header/ui/ScaleImage.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
ScaleImage::ScaleImage(TEXTURE_ID _id, const GSvector2& _position, bool _isPexis)
	:m_id(_id), m_position(_position),
	m_scaleLerp(GSvector2(1.0f, 1.0f)),
	m_moveLerp(m_position),
	m_isPexis(_isPexis),
	m_change(false)
{
}

ScaleImage::~ScaleImage()
{
}

void ScaleImage::start(const GSvector2 & _start, const GSvector2 & _end, float _time)
{
	m_scaleLerp.start(_start, _end, _time);
}
void ScaleImage::moveStart(const GSvector2 & _end, float _time)
{
	m_moveLerp.start(m_position, _end, _time);
}
void ScaleImage::update(float deltaTime)
{
	m_scaleLerp.update(deltaTime);
	m_moveLerp.update(deltaTime);
	if (!m_change)
	{
		scroll();
		return;
	};
	m_position = m_moveLerp.current() + GSvector2(180.0f, 0);
}

void ScaleImage::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	GSvector2 scale = m_scaleLerp.current();
	desc.matrix.scale(scale);
	desc.matrix.translate(m_position);
	desc.textureID = static_cast<GSuint>(m_id);
	_renderer->render(desc);
}
void ScaleImage::scroll()
{
	m_position.x++;
	if (m_position.x >= 180)
	{
		m_change = true;
	}
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
