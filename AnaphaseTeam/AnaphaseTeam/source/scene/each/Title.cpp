#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/device/Input.h"

#include "../../../header/actor/TestActor.h"

Title::Title(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Camera(10, 8, GSvector3(0,5, 0)),
	target(0,5, -10),
	//target(nullptr),
	actorManager(),
	m_Map(OCTREE_ID::KOUTEI)
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
	for (int i = 0; i <10; i++)
	{
		Actor_Ptr actor = std::make_shared<TestActor>();
		actor->initialize();
		actorManager.add(actor);
	}

	/*target = actorManager.findif([&](Actor_Ptr _actor)
	{
		return target != _actor&&_actor->cameraDistance(m_Camera);
	});*/
}
void Title::update(float deltaTime)
{
	target.x -= m_Input->horizontal()*0.1f;
	target.z += m_Input->vertical()*0.1f;
	target.y += m_Input->ymove()*0.1f;
	/*if (m_Input->upTrigger())
	{
		target = actorManager.findif([&](Actor_Ptr _actor)
		{
			return target != _actor&&_actor->cameraDistance(m_Camera);
		});
	}*/

	actorManager.accept([deltaTime](Actor_Ptr _actor) {_actor->update(deltaTime);});
	actorManager.accept([&](Actor_Ptr _actor) {_actor->collisionGround(m_Map);});

	actorManager.remove([](Actor_Ptr _actor)->bool {return _actor->isDead();});
}

void Title::draw(const Renderer & renderer)
{	
	m_Camera.lookAt(target, 0);
	
	//target->cameraChases(m_Camera);

	m_Map.draw(renderer);
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
