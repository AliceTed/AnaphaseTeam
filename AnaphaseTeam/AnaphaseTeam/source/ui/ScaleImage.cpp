#include "../../header/ui/ScaleImage.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

ScaleImage::ScaleImage(TEXTURE_ID _id, const GSvector2& _position, bool _isPexis, float _stopPos, float _alpha)
	:m_id(_id), m_position(_position),
	m_scaleLerp(GSvector2(1.0f, 1.0f)),
	m_moveLerp(GSvector2(_stopPos, m_position.y)),
	m_changeScroll(false),
	m_alpha(_alpha), m_value(0.0f), m_speed(10.0f),
	m_stopPos(_stopPos)

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
	desc.center = getTextureSize()*0.5f;
	desc.matrix.scale(scale);
	desc.matrix.translate(m_position + desc.center);
	desc.color.a = m_alpha;
	desc.textureID = static_cast<GSuint>(m_id);
	_renderer->render(desc);
}

void ScaleImage::scroll()
{
	m_position.x += m_speed;

	if (m_position.x > 375)
	{
		m_speed -= 0.5;
	}

	if (m_position.x >= m_stopPos)
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

float ScaleImage::isPos()
{
	return m_position.x;
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
