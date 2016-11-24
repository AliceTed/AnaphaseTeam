#include "../../header/ui/Fade.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/RectangleRenderDesc.h"
#include "../../header/renderer/define/ViewportDesc.h"
Fade::Fade()
	:m_isStart(false),
	m_Lerp(GScolor(0,0,0,0)),
	m_endfunc(nullptr)
{
}

Fade::~Fade()
{
}

void Fade::initialize()
{
	m_isStart = false;
}
void Fade::update(float deltaTime)
{
	if (!m_isStart)return;
	m_Lerp.update(deltaTime);
	endFunction();
}
void Fade::start(const GScolor& _startColor, const GScolor& _endColor, float _time/*second*/,const std::function<void()>& _end)
{
	m_isStart = true;
	m_Lerp.start(_startColor,_endColor,_time);
	m_endfunc = _end;
}

void Fade::stop()
{
	m_isStart = false;
}

const bool Fade::isStart()const
{
	return m_isStart;
}

const bool Fade::isEnd()const
{
	return m_Lerp.isEnd();
}
/*void setMode(FadeMode mode)
{

}*/
void Fade::draw(IRenderer * renderer)
{
	RectangleRenderDesc desc;
	desc.color = m_Lerp.current();
	ViewportDesc view = renderer->getViewPort();
	desc.rect = GSrect(0,0,view.width,view.height);
	renderer->render(desc);
}

void Fade::endFunction()
{
	if (!m_Lerp.isEnd())return;
	m_isStart = false;
	if (m_endfunc == nullptr)return;
	m_endfunc();
}
