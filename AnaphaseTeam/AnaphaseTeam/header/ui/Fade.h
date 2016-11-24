#ifndef _FADE_H_
#define _FADE_H_
#include <gslib.h>
#include <functional>
#include "../math/TimeLerpVector.h"
class IRenderer;
class Fade
{
public:
	Fade();
	~Fade();
	void initialize();
	void update(float deltaTime);
	//end 終了時に呼ばれる関数
	void start(const GScolor& _startColor, const GScolor& _endColor, float _time/*second*/, const std::function<void()>& _end=nullptr);
	void stop();
	/*startしてるか？*/
	const bool isStart()const;
	const bool isEnd()const;
	void draw(IRenderer * renderer);
private:
	void endFunction();
private:
	bool m_isStart;
	Math::TimeLerpVector<GScolor> m_Lerp;
	std::function<void()> m_endfunc;
};
#endif
