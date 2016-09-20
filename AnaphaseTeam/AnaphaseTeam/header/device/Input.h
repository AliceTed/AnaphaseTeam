#ifndef _INPUT_H_
#define _INPUT_H_
#include <gslib.h>
class Input
{
public:
	Input();
	const GSvector2 velocity()const;
	//êÖïΩ
	const int horizontal()const;
	//êÇíº
	const int vertical()const;

	const int rotate()const;

	const bool jumpTrigger()const;
	const bool chainTrigger()const;
	const bool attckTrigger()const;

	//input?
	const bool move()const;
	const bool walk()const;
};
#endif