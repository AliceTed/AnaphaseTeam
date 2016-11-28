#ifndef _FADE_H_
#define _FADE_H_
#include <gslib.h>
#include <functional>
#include "../math/TimeLerpVector.h"
#include "../../header/data/TEXTURE_ID.h"
class Renderer;
class Fade
{
public:
	Fade(TEXTURE_ID _id = TEXTURE_ID::BLACK, const GSvector2& _position = GSvector2(0.0f,0.0f));
	~Fade();
	void initialize();
	void update(float deltaTime);
	//end èIóπéûÇ…åƒÇŒÇÍÇÈä÷êî
	void start(const GScolor& _startColor, const GScolor& _endColor, float _time/*second*/, const std::function<void()>& _end=nullptr);
	void stop();
	/*startÇµÇƒÇÈÇ©ÅH*/
	const bool isStart()const;
	const bool isEnd()const;
	void draw(const Renderer& renderer);
private:
	void endFunction();
private:
	bool m_isStart;
	Math::TimeLerpVector<GScolor> m_Lerp;
	std::function<void()> m_endfunc;
	GSvector2 m_position;
	TEXTURE_ID m_TextureID;
};
#endif
