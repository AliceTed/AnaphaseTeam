#ifndef _INPUT_H_
#define _INPUT_H_
#include <gslib.h>
class Input
{
public:
	Input();
	const GSvector2 velocity()const;
	//����
	const int horizontal()const;
	//����
	const int vertical()const;

	const int rotate()const;

	const bool jumpTrigger()const;
	const bool chainTrigger()const;
	const bool attackTrigger() const;
	const bool scytheTrigger()const;
	const bool gunTrigger()const;

	//input?
	const bool move()const;
	const bool walk()const;

	const bool up()const;
	const bool down()const;
	const bool exit()const;
};
#endif