#ifndef _INPUT_H_
#define _INPUT_H_
#include <gslib.h>
class Input
{
public:
	Input();
	const GSvector2 velocity()const;
	//…•½
	const int horizontal()const;
	//‚’¼
	const int vertical()const;

	const int rotate()const;

	const bool jumpTrigger()const;
};
#endif