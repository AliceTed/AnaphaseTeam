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
};
#endif