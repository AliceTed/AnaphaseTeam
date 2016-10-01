#ifndef _INPUT_H_
#define _INPUT_H_
#include <gslib.h>
class Input
{
public:
	Input();
	const bool isJoyTriggerUp() const;
	const bool isJoyTriggerDown() const;
	const bool isJoyTriggerLeft() const;
	const bool isJoyTriggerRight() const;
	const bool isJoyTriggerA() const;
	const bool isJoyTriggerB() const;
	const bool isJoyTriggerX() const;
	const bool isJoyTriggerY() const;
	const bool isJoyTriggerLB() const;
	const bool isJoyTriggerRB() const;
	const bool isJoyTriggerBACK() const;
	const bool isJoyTriggerSTART() const;
	const bool isJoyTriggerLeftThrust() const;
	const bool isJoyTriggerRightThrust() const;
	const GSvector2 leftPadAxis() const;
	const GSvector2 rightPadAxis() const;
	const bool isJoyLeftTrigger();
	const bool isJoyRightTrigger();
	const bool isEscapeTrigger()const;
private:
 	bool m_previousLeftTrigger;
	bool m_previousRightTrigger;
};
#endif