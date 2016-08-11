#include "../../../header/scene/each/Title.h"
Title::Title()
	:m_IsEnd(false)
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
}

void Title::draw(const Renderer & renderer)
{
	
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
