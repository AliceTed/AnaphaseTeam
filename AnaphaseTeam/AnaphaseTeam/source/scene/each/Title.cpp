#include "../../../header/scene/each/Title.h"
#include "../../../header/renderer/Renderer.h"

#include "../../../header/device/Input.h"

#include "../../../header/actor/TestActor.h"

Title::Title(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_Camera(10, 8, GSvector3(0, 5, 0)),
	actorManager(),
	m_Map(OCTREE_ID::KOUTEI),
	player(_input)
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
	for (int i = 0; i <20; i++)
	{
		Actor_Ptr actor = std::make_shared<TestActor>();
		actor->initialize();
		actorManager.add(actor);
	}
	player.initialize();
	/*target = actorManager.findif([&](Actor_Ptr _actor)
	{
		return target != _actor&&_actor->cameraDistance(m_Camera);
	});*/
}
void Title::update(float deltaTime)
{
	/*if (m_Input->upTrigger())
	{
		target = actorManager.findif([&](Actor_Ptr _actor)
		{
			return target != _actor&&_actor->cameraDistance(m_Camera);
		});
	}*/
	player.update(deltaTime);
	player.collisionGround(m_Map);

	actorManager.accept([deltaTime](Actor_Ptr _actor) {_actor->update(deltaTime);});
	actorManager.accept([&](Actor_Ptr _actor) {_actor->collisionGround(m_Map);});

	actorManager.remove([](Actor_Ptr _actor)->bool {return _actor->isDead();});
}

void Title::draw(const Renderer & renderer)
{
	renderer.getDraw3D().drawSky(MESH_ID::SKY);
	//m_Camera.lookAt(target, 0);	
	player.draw(renderer,m_Camera);

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
