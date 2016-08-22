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
	player(_input),
	collision(),
	ob1(GSvector3(0, 4, 0),GSvector3(1,1,1), GSvector3(0, 0, 0)),
	seg(GSvector3(0,4,0),GSvector3(0,1,0))
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsEnd = false;
	collision.initialize();
	for (int i = 0; i < 20; i++)
	{
		Actor_Ptr actor = std::make_shared<TestActor>();
		actor->initialize();
		actorManager.add(actor);
	}
	player.initialize();
}
void Title::update(float deltaTime)
{
	player.update(deltaTime);
	player.collisionGround(m_Map);
	player.createCollision(&collision);

	actorManager.accept([deltaTime](Actor_Ptr _actor) {_actor->update(deltaTime);});
	actorManager.accept([&](Actor_Ptr _actor) {_actor->collisionGround(m_Map);});
	actorManager.accept([&](Actor_Ptr _actor) {_actor->createCollision(&collision);});

	collision.update(deltaTime);
	actorManager.remove([](Actor_Ptr _actor)->bool {return _actor->isDead();});

	GSvector3 move(gsGetKeyState(GKEY_Y) - gsGetKeyState(GKEY_U),
		gsGetKeyState(GKEY_H) - gsGetKeyState(GKEY_J),
		gsGetKeyState(GKEY_N) - gsGetKeyState(GKEY_M));

	ob1.move(move*0.1f);
	GSvector3 rot(gsGetKeyState(GKEY_R) - gsGetKeyState(GKEY_T),
		gsGetKeyState(GKEY_F) - gsGetKeyState(GKEY_G),
		gsGetKeyState(GKEY_V) - gsGetKeyState(GKEY_B));
	ob1.rot(rot);
}

void Title::draw(const Renderer & renderer)
{
	renderer.getDraw3D().drawSky(MESH_ID::SKY);
	//m_Camera.lookAt(target, 0);	
	player.draw(renderer, m_Camera);

	//m_Map.draw(renderer);

	actorManager.accept([&](Actor_Ptr _actor) {_actor->draw(renderer, m_Camera);});
	renderer.getDraw2D().string("ëçêî:" + std::to_string(actorManager.size()), &GSvector2(20, 20), 20);
	renderer.getDraw2D().string("ï`âÊêî:" + std::to_string(TestActor::DrawCount), &GSvector2(20, 50), 20);
	collision.draw(renderer);

	GScolor c = { 1,1,1,1 };
	if (ob1.TestSegmentOBB(&seg))
	{
		c = { 1,0,0,1 };
	}
	ob1.draw(renderer, c);
	seg.draw(renderer);
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
