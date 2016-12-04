#include "../../header/ui/HPGaugeUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/actor/Player/Status.h"

const float HPGaugeUI::MAGNI = 10;

HPGaugeUI::HPGaugeUI(Status& _status)
	:m_status(_status)
{
	m_maxHelth = m_status.getHp()*10;
}
HPGaugeUI::~HPGaugeUI()
{
}
void HPGaugeUI::update(float deltaTime)
{
}

void HPGaugeUI::draw(IRenderer * _renderer)
{
	GSmatrix4 mat;
	mat.identity();
	mat.translate(0, 10, 0);

	SpriteRectRenderDesc back;
	back.textureID = static_cast<GSuint>(TEXTURE_ID::BLACK);
	back.matrix = mat;
	back.srcRect = GSrect(0, 0, 100*MAGNI, 30);
	_renderer->render(back);


	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::WHITE);
	front.matrix = mat;
	front.srcRect = GSrect(0, 0, m_status.getHp() * MAGNI, 30);
	front.color = GScolor(0.0f, 1.0f, 0.0f, 1.0f);
	_renderer->render(front);
}
