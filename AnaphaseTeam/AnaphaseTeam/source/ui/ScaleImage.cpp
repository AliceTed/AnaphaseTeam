#include "../../header/ui/ScaleImage.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
static const float  endPosiX = 465;

ScaleImage::ScaleImage(TEXTURE_ID _id, const GSvector2& _position, bool _isPexis)
	:m_id(_id), m_position(_position),
	m_scaleLerp(GSvector2(1.0f, 1.0f)),
	m_moveLerp(GSvector2(endPosiX, m_position.y)),
	m_changeScroll(false),
	m_alpha(0.0f), m_value(0.0f),
	m_speed(10.0f)

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
	if (!m_changeScroll)
	{
		scroll();
		alpha(1.0f);
		return;
	};
	m_position = m_moveLerp.current();
}

void ScaleImage::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	GSvector2 scale = m_scaleLerp.current();
	desc.center = GSvector2(m_position.x / 2, m_position.y / 2);
	desc.matrix.scale(scale);
	desc.matrix.translate(m_position+desc.center);
	desc.color.a = m_alpha;
	desc.textureID = static_cast<GSuint>(m_id);
	_renderer->render(desc);
}

void ScaleImage::scroll()
{
	m_position.x += m_speed;

	if (m_position.x > 365)
	{
		m_speed -= 0.5;
	}

	if (m_position.x >= endPosiX)
	{
		m_changeScroll = true;
	}
}

void ScaleImage::alpha(float _timer)
{
	m_value = 1 / (_timer * 60);
	if (m_alpha <= 1.0f)
	{
		m_alpha += m_value;
	}
}

bool ScaleImage::isEndscroll()
{
	return m_changeScroll;
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
