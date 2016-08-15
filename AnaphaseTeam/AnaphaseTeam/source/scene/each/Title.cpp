#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/device/Input.h"
#include "../../../header/shape/Sphere.h"

#include "../../../header/actor/TestActor.h"

#include "../../../header/math/Random.h"
Title::Title(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Camera(10, 8, GSvector3(0, 0, 0)),
	target(0, 0, -10),
	actorManager()
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
	Math::Random rnd;
	for (int i = 0; i < 10; i++)
	{
		Sphere sphere(GSvector3(rnd(-10,10,i), rnd(-10, 10, i),rnd(-10, 10, i)), rnd(0.3f,1.0f));
		Actor_Ptr actor = std::make_shared<TestActor>(sphere);
		actor->initialize();
		actorManager.add(actor);
	}
}
void Title::update(float deltaTime)
{
	target.x -= m_Input->horizontal()*0.1f;
	target.z += m_Input->vertical()*0.1f;
	target.y += m_Input->ymove()*0.1f;

	actorManager.accept([deltaTime](Actor_Ptr _actor) {_actor->update(deltaTime);});
	actorManager.remove([](Actor_Ptr _actor)->bool {return _actor->isDead();});
}

void Title::draw(const Renderer & renderer)
{
	m_Camera.lookAt(target, 0);
	actorManager.accept([&](Actor_Ptr _actor) {_actor->draw(renderer, m_Camera);});
	renderer.getDraw2D().string(std::to_string(actorManager.size()),&GSvector2(20,20),20);
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
