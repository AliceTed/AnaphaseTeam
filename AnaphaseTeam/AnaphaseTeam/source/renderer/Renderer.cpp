#include "../../header/renderer/Renderer.h"

Renderer::Renderer()
	:m_Draw2D(),m_Draw3D()
{
}
const Draw2D & Renderer::getDraw2D() const
{
	return m_Draw2D;
}

const Draw3D & Renderer::getDraw3D() const
{
	return m_Draw3D;
}
