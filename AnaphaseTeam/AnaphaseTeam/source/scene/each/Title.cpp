#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/device/Input.h"

#include "../../../header/actor/TestActor.h"

Title::Title(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Camera(10, 8, GSvector3(0, 0, 0)),
	target(0, 0, -20),
	actorManager()
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
	for (int i = 0; i <50; i++)
	{
		Actor_Ptr actor = std::make_shared<TestActor>();
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
	renderer.getDraw2D().string("ëçêî:"+std::to_string(actorManager.size()),&GSvector2(20,20),20);
	renderer.getDraw2D().string("ï`âÊêî:" + std::to_string(TestActor::DrawCount), &GSvector2(20,50), 20);	
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
