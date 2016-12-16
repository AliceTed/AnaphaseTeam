#include "../../header/ui/HPGaugeUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/actor/Player/Status.h"

HPGaugeUI::HPGaugeUI(const GSvector2 & _posistion,Status& _status, float _scale)
	:m_status(_status),
	m_posistion(_posistion),
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
	back.textureID = static_cast<GSuint>(TEXTURE_ID::PLAYER_HP);
	back.matrix = mat;
	//back.srcRect = GSrect(0, 0, m_status.getMaxHp() * m_scale, 30);
	_renderer->render(back);


	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::PLAYER_HP_GAUGE);
	mat.translate(102.0f, 0.0f, 0);
	front.matrix = mat;
	front.srcRect = GSrect(0, 0, m_status.getHp() * m_scale, 125);
	/*front.color = GScolor(0.0f, 1.0f, 0.0f, 1.0f);*/
	_renderer->render(front);
}
