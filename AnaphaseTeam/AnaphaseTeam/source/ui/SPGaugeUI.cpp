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
	//SpriteRectRenderDesc back;
	//back.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_GAUGE);
	//back.matrix.translate(0, 120, 0);
	//back.srcRect = GSrect(0, 0, (int)RankGauge::MAX, 30);
	//_renderer->render(back);
	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_GAUGE);
	front.matrix.translate(1170, 80, 0);
	float percent = m_gauge.getGauge() / (int)RankGauge::MAX * 100;
	front.srcRect = GSrect(0, percent, 123, 119);//123,119
	_renderer->render(front);
}