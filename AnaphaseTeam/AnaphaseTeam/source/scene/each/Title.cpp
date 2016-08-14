#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/device/Input.h"
Title::Title(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Camera(10, 8, GSvector3(0, 0, 0)),
	target(0, 0, 0),
	light(GL_LIGHT0, GSvector3(0, 1, 0))
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
}
void Title::update(float deltaTime)
{
	target.x += m_Input->horizontal()*0.1f;
	target.z += m_Input->vertical()*0.1f;
}

void Title::draw(const Renderer & renderer)
{
	m_Camera.lookAt(target, 0);
	light.lighting();

	GSvector3 pos(0, 0, 0);
	float radius(2);

	bool isDraw = m_Camera.isFrustumCulling(pos, 2);

	//ƒ¿’l‚ð‰º‚°Žn‚ß‚é‹——£
	float maxfar = 10.0f;

	if (isDraw)
	{
		float marge = m_Camera.nearMargeDistance(pos, radius);

		GScolor color(1, 0, 0, marge / maxfar);
		renderer.getDraw2D().string(std::to_string(color.a), &GSvector2(100, 0), 20, &GScolor(1, 0, 0, 1));

		renderer.getDraw3D().drawSphere(&pos, radius, color);
	}
	std::string str = isDraw ? "Draw" : "Non";
	renderer.getDraw2D().string(str, &GSvector2(0, 0), 20);
	renderer.getDraw2D().textrue(TEXTURE_ID::TEST,&GSvector2(100,50));
}

void Title::finish()
{
}

const SceneMode Title::next() const
{
	return SceneMode::GAMEPLAY;
}

const bool Title::isEnd() const
{
	return m_IsEnd;
}
