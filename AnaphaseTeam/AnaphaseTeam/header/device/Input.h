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
	const bool upTrigger()const;
	const bool downTrigger()const;
};
#endif