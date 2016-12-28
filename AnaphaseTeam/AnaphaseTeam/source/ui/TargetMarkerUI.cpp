#include "../../header/ui/TargetMarkerUI.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/ViewportDesc.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/actor/Player/Player.h"

TargetMarkerUI::TargetMarkerUI(const GSvector3 & _position, Player* _player)
	:m_position(_position),
	m_scale(1.0f),
	m_player(_player)
{
}

void TargetMarkerUI::update(float deltaTime)
{
	m_scale = m_player->distance(m_position) * 0.1f;
}

void TargetMarkerUI::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_MAIN);
	GStexture* tex = gsGetTexture(desc.textureID);
	desc.center = GSvector2(tex->dwWidth, tex->dwHeight) * 0.5f;
	GSvector3 target = transform(_renderer);

	float size = target.z / 1.0f;
	m_scale = (1 - size) * 20;

	//m_scale = CLAMP(1/target.z, 0.5f, 1.0f);
	desc.matrix.scale(m_scale, m_scale, m_scale);
	desc.matrix.translate(target);
	_renderer->render(desc);
}

GSvector3 TargetMarkerUI::transform(IRenderer* _renderer)
{
	ViewportDesc viewport = _renderer->getViewPort();
	float w = viewport.width * 0.5f;
	float h = viewport.height * 0.5f;

	Matrix4 screen = {
		w   , 0.0f,0.0f,0.0f,
		0.0f, -h  ,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		w + viewport.x, h + viewport.y, 0.0f,1.0f
	};
	Matrix4 projection = _renderer->getProjectionMatrix();
	Matrix4 view = _renderer->getViewMatrix();
	return m_position * view * projection * screen;
}
