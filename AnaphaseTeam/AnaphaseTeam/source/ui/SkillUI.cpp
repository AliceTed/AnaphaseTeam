#include "..\..\header\ui\SkillUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/myanimation/MyAnimationFunc.h"
SkillUI::SkillUI(TEXTURE_ID _textureID, MYANIMATION_ID _animationID, const GScolor & _color)
	:m_textureID(_textureID),
	m_animationID(_animationID),
	m_color(1,1,1,1),
	m_selectColor(_color),
	m_transform(),
	m_isOpen(false)
{
}

void SkillUI::initialize()
{
	//m_isOpen = false;
	m_color = { 1,1,1,1 };
}

void SkillUI::open()
{
	m_isOpen = true;
	startMyAnimation(static_cast<unsigned int>(m_animationID), &m_transform);
}

void SkillUI::close()
{
	m_isOpen = false;
	startMyAnimation(static_cast<unsigned int>(m_animationID), &m_transform,MYANIMATION_MODE::REVERSE);
}

void SkillUI::canSelect()
{
	m_color = m_selectColor;
	m_color.a = 0.5f;
}

void SkillUI::select()
{
	m_color = m_selectColor;
}

void SkillUI::update(float deltaTime)
{
	updateMyAnimation(static_cast<unsigned int>(m_animationID), deltaTime);
}

void SkillUI::draw(IRenderer * _renderer, const GSvector2 & _pivot)
{
	SpriteRenderDesc desc;
	desc.matrix = m_transform.parent_synthesis(Transform({ 0,0,0 }, _pivot)).matrix();
	desc.center=  GSvector2(44, 41);
	desc.textureID = static_cast<GSuint>(m_textureID);
	desc.color = m_color;
	_renderer->render(desc);
}

const bool SkillUI::isOpen() const
{
	return m_isOpen;
}

