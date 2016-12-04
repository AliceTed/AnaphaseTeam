#include "../../header/ui/ScaleImage.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
ScaleImage::ScaleImage(TEXTURE_ID _id, const GSvector2& _position, bool _isPexis)
	:m_id(_id), m_position(_position),
	m_scaleLerp(GSvector2(1.0f, 1.0f)),
	m_moveLerp(m_position),
	m_isPexis(_isPexis),
	m_a(false)
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
	if (!m_a)
	{
		scroll();
	};
	m_scaleLerp.update(deltaTime);
	m_moveLerp.update(deltaTime);
}

void ScaleImage::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	GSvector2 scale = m_scaleLerp.current();
	GSvector2 pos = m_moveLerp.current();
	if (m_a) 
	{
		m_position = m_moveLerp.current() + GSvector2(180.0f, 0);
		if (!m_isPexis)
		{
			//m_position -= getSizeMarge(scale)*0.5f;
			//pos  -= getSizeMarge(scale)*0.5f;
			//pod -= getSizeMarge(scale)*0.5f;
		}
		//desc.matrix.scale(scale);
		//.matrix.translate(pos);
		//desc.matrix.translate(m_position);
		//desc.matrix.translate(pod);
		//desc.textureID = static_cast<GSuint>(m_id);
	}
	
	//if (m_a)
	//{
		//desc.matrix.translate(m_position);
		//desc.textureID = static_cast<GSuint>(m_id);
		
	//}
	desc.matrix.scale(scale);
	//desc.matrix.translate(pos);
	desc.matrix.translate(m_position);
	desc.textureID = static_cast<GSuint>(m_id);
	_renderer->render(desc);
}
void ScaleImage::scroll()
{
	m_a = false;
	if (m_position.x < 180)
	{
		m_position.x ++;
		
	}
	if (m_position.x >= 180)
	{
		m_position.x = 180;
		m_a = true;
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
