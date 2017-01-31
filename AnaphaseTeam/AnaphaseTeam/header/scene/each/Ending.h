#ifndef _ENDING_H_
#define _ENDING_H_
#include "../IScene.h"
#include "../SceneChange.h"
#include "../../ui/EndingUI.h"

class Ending : public IScene
{
public:
	Ending();
	~Ending();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
	void endScene();
private:
	bool m_IsEnd;
	SceneChange m_change;
	EndingUI m_endUI;
	bool m_nex;
	int m_count;
};
#endif