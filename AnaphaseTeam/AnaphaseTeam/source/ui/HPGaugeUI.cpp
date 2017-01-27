#include "../../header/ui/HPGaugeUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/actor/Player/Status.h"
#include "../../header/math/Calculate.h"

HPGaugeUI::HPGaugeUI(const GSvector2 & _posistion, Status& _status, TEXTURE_ID _hpID, TEXTURE_ID _hpGaugeID, float _scale)
	:m_status(_status),
	m_posistion(_posistion),
	m_hpID(_hpID),
	m_hpGaugeID(_hpGaugeID),
	m_scale(_scale)
{
}
void HPGaugeUI::update(float deltaTime)
{
}

void HPGaugeUI::draw(IRenderer * _renderer)
{
	GSmatrix4 mat;
	mat.identity();
	mat.translate(m_posistion);

	SpriteRenderDesc back;
	back.textureID = static_cast<GSuint>(m_hpID);
	back.matrix = mat;
	//back.srcRect = GSrect(0, 0, m_status.getMaxHp() * m_scale, 30);
	_renderer->render(back);


	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(m_hpGaugeID);


	if (m_hpGaugeID == TEXTURE_ID::ENEMY_HP_GAUGE)
	{
		float m = (m_status.getMaxHp() * m_scale)-(m_status.getHp() * m_scale);
		front.srcRect = GSrect(m, 0, m_status.getMaxHp() * m_scale, 125);
		mat.translate(m, 0.0f, 0);
		
	}
	if (m_hpGaugeID == TEXTURE_ID::PLAYER_HP_GAUGE)
	{
		front.srcRect = GSrect(0, 0, m_status.getHp() * m_scale, 125);
	}
	mat.translate(102.0f, 0.0f, 0);

	front.matrix = mat;
	/*front.color = GScolor(0.0f, 1.0f, 0.0f, 1.0f);*/
	_renderer->render(front);
}
