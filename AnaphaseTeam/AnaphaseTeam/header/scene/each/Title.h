#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"

class Input;
typedef std::shared_ptr<Actor>Actor_Ptr;
class Title :public IScene
{
public:
	Title(const Input* _input);
	~Title();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	const Input* m_Input;

};
#endif