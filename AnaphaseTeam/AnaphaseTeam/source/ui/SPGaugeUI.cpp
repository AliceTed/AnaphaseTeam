#include "../../header/ui/SPGaugeUI.h"
#include "../../header/renderer/IRenderer.h"
#include"../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/actor/Player/Gauge.h"
#include <gslib.h>
SPGaugeUI::SPGaugeUI(Gauge& _gauge)
	:m_gauge(_gauge)
{}
SPGaugeUI::~SPGaugeUI()
{}
void SPGaugeUI::update(float deltaTime)
{}
void SPGaugeUI::draw(IRenderer *_renderer)
{
	SpriteRectRenderDesc back;
	back.textureID = static_cast<GSuint>(TEXTURE_ID::BLACK);
	back.matrix.translate(0, 120, 0);
	back.srcRect = GSrect(0, 0, (int)RankGauge::MAX, 30);
	_renderer->render(back);

	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::WHITE);
	front.matrix.translate(0, 120, 0);
	front.srcRect = GSrect(0, 0, m_gauge.getGauge(), 30);
	front.color = GScolor(1.0f, 1.0f, 0.0f, 1.0f);
	_renderer->render(front);
}