#include "..\..\header\ui\SkillUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/myanimation/MyAnimationFunc.h"
SkillUI::SkillUI(const GSvector2& _position, TEXTURE_ID _textureID, MYANIMATION_ID _animationID, const GScolor & _color)
	:m_textureID(_textureID),
	m_animationID(_animationID),
	m_color(_color),
	m_transform(),
	m_point(_position)
{
}

void SkillUI::initialize()
{
}

void SkillUI::start()
{
	startMyAnimation(static_cast<unsigned int>(m_animationID), &m_transform);
}

void SkillUI::rev()
{
	startMyAnimation(static_cast<unsigned int>(m_animationID), &m_transform,MYANIMATION_MODE::REVERSE);
}

void SkillUI::update(float deltaTime)
{
	updateMyAnimation(static_cast<unsigned int>(m_animationID), deltaTime);
}

void SkillUI::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.matrix = m_transform.parent_synthesis(Transform({0,0,0},m_point)).matrix();
	desc.textureID = static_cast<GSuint>(m_textureID);
	_renderer->render(desc);
}
